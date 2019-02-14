set -e
set -x
echo "Tensorflow for Python2.7 Setup"
wget http://xiaoshuangwang.net/tensorflow-1.8.0-cp27-cp27mu-linux_aarch64.whl
sudo pip2 install tensorflow-1.8.0-cp27-cp27mu-linux_aarch64.whl
echo "Tensorflow for Python3.5 Setup"
wget http://xiaoshuangwang.net/tensorflow-1.8.0-cp35-cp35m-linux_aarch64.whl
sudo pip3 install tensorflow-1.8.0-cp35-cp35m-linux_aarch64.whl
