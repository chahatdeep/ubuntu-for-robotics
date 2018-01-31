If you are using the **USB2AX**, you will need to reconfigure the Linux kernel to enable USB Modem Support. We followed [this simple tutorial](http://www.jetsonhacks.com/2017/03/25/build-kernel-and-modules-nvidia-jetson-tx2/) from JetsonHacks to reconfigure the kernel. **IMPORTANT: before executing ./makeKernel.h execute the command below.**

    sudo sed -i 's/.*CONFIG_USB_ACM.*/CONFIG_USB_ACM=y/' /usr/src/kernel/kernel-4.4/.config

After following the tutorial and rebooting the Jetson plug in the USB2AX and type:

    dmesg | grep acm 

You should receive an output like this

    nvidia@tegra-ubuntu:~ $ dmesg | grep acm
    [   38.506490] cdc_acm 1-1:1.0: ttyACM0: USB ACM device
    [   38.506689] usbcore: registered new interface driver cdc_acm
    [   38.506690] cdc_acm: USB Abstract Control Model driver for USB modems and ISDN adapters

    