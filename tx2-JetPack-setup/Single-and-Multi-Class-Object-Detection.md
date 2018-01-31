### Creating a Single Class Network for Object Detection
1. Collect images of the item in one class of the neural network and label them as class_name_1. 
2. Using DIGITS, create a dataset of the images. In the Custom Classes section, add ‘dontcare, class_name_1.’
<p align="center">
  <img src="https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/datacreate1.png" />
</p>


<p align="center">
  <img src="https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/datacreate2.png" />
</p>

3) Once the dataset has been successfully created, create a model that uses the dataset to train. Make sure to select the dataset that was made in in the previous dataset. Change ‘Subtract Mean’ to ‘None,’ set ‘Solver Type’ to ‘Adam,’ and change the ‘Base Learning Rate’ to 0.0001. The learning rate and number of training epochs can be altered based on how well the model works or doesn’t work. In the Custom Network tab below, add the [prototxt file](https://github.com/dusty-nv/jetson-inference/blob/master/data/networks/detectnet.prototxt) for one class. In the ‘deploy_data’ layer, ‘train_transform’ layer, ‘val_transform’ layer, ‘cluster bboxes’ layer, and both mAP layers, change the dimensions to the custom dimensions used during dataset creation. If there is a model previously trained that worked well, this model can be trained off of that. If not, add the ‘bvlc_googlenet.caffemodel’ in ‘Pretrained Models’ under the prototxt file. Run the model.
<p align="center">
  <img src="https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/modelcreate1.png" />
</p>
<p align="center">
  <img src="https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/modelcreate2.png" />
</p>
<p align="center">
  <img src="https://github.com/NVIDIA-Jetson/jetson-trashformers/blob/master/images/modelcreate3.png" />
</p>

4. Once the model is done running, deploy it on the Jetson TX2 following [these instructions](https://github.com/dusty-nv/jetson-inference/#system-setup). The model can be run again based on previous models for improvement. When the model performs well, multiple classes can be added to the dataset.
5. Collect images of the item in the second class of the neural network and label them as class_name_2.   
6. Create a dataset with images of both class_name_1 and class_name_2. In the ‘Custom Classes’ section, add ‘dontcare, class_name_1, class_name_2’ as the class labels. All other settings can follow Step 2 from above.   
7. Once the dataset is created, follow the instructions above to create a model. In the ‘Custom Network’ tab, add the [protoxt for two classes](https://raw.githubusercontent.com/NVIDIA/caffe/caffe-0.15/examples/kitti/detectnet_network-2classes.prototxt) and change the dimensions. In the ‘Previous Networks’ tab, select the model created in the previous steps for one class.   
8. Train the model, then repeat Step 4 to improve it.   
9. To train for more than two classes, repeat all the steps above, and make the [following changes](https://lesterlo.wordpress.com/2017/05/10/train-multiple-classes-in-detectnet/) to the two class prototxt file. 
* In the ‘train_transform’ and ‘val_transform’ layers, add object_class fields to match the number of classes needed.

```
object_class: { src: 1 dst: 0} # cars -> 0
object_class: { src: 8 dst: 1} # pedestrians -> 1
```

* Change num_output in the convolution parameter to the number of classes (around line 2380).

```
num_output: 2
```

* In the ‘cluster bboxes’ layer, add the top layer parameter for all classes (around line 2500).

```
top: 'bbox-list-class0'
top: 'bbox-list-class1'
```

* In the ‘cluster bboxes’ layer, change the last parameter of the param_str to the number of classes.

```
param_str : '1248, 352, 16, 0.6, 3, 0.02, 22, 2'
```

* In the ‘calculate mAP’ layer, add the top layer parameter for all classes (around line 2500).

```
top: 'bbox-list-label-class0'
top: 'bbox-list-label-class1'
```

* In the ‘calculate mAP’ layer, change the last parameter of the param_str to the number of classes.

```
param_str : '1248, 352, 16, 2'
```

* Create final output layers for each of the classes being trained. 
```
layer {
    type: 'Python'
    name: 'score-class0'
    bottom: 'bbox-list-label-class0'
    bottom: 'bbox-list-class0'
    top: 'bbox-list-scored-class0'
    python_param {
        module: 'caffe.layers.detectnet.mean_ap'
        layer: 'ScoreDetections'
    }
    include: { phase: TEST stage: "val" }
}
layer {
    type: 'Python'
    name: 'mAP-class0'
    bottom: 'bbox-list-scored-class0'
    top: 'mAP-class0'
    top: 'precision-class0'
    top: 'recall-class0'
    python_param {
        module: 'caffe.layers.detectnet.mean_ap'
        layer: 'mAP'
        param_str : '1248, 352, 16'
    }
    include: { phase: TEST stage: "val" }
}
```