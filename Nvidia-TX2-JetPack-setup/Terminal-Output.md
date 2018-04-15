## Terminal Output:

```sh
sudo ./install.sh
```

```sh
chahatdeep@archahat:~/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/CTI-L4T$ sudo ./install.sh 
[sudo] password for chahatdeep: 
  Usage: ./install.sh 
  Before installing this BSP, please read the included readme.txt
  To switch between different products, the TX2 will need to be re-flashed
  Below are the compatible L4T versions and board profiles:

Supported Version Information
  CTI-L4T Board Support Package Version: V110
  Supported CTI Products (profiles): 
     astro-mpcie
     astro-usb3
     astro-revG+
     elroy-mpcie
     elroy-usb3
     elroy-revF+
     orbitty
     rosie
     rudi-mpcie
     rudi-usb3
     rudi
     sprocket
     spacely
     spacely-IMX185-3CAM
     spacely-IMX274-3CAM
     cogswell
     graphite-vpx
  Supported Linux for Tegra Release Versions: 
     28.1.0
  Supported Nvidia Jetson Module Hardware: 
     TX2
~/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2 ~/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/CTI-L4T
Using rootfs directory of: /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs
Extracting the NVIDIA user space components to /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs
Extracting the BSP test tools to /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs
Extracting the NVIDIA gst test applications to /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs
Extracting the configuration files for the supplied root filesystem to /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs
Creating a symbolic link nvgstplayer pointing to nvgstplayer-1.0
Creating a symbolic link nvgstcapture pointing to nvgstcapture-1.0
Extracting Weston to /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs
Adding symlink libcuda.so --> libcuda.so.1.1 in target rootfs
Adding symlink libGL.so --> libGL.so.1 in target rootfs
Adding symlink libnvbuf_utils.so --> libnvbuf_utils.so.1.0.0 in target rootfs
Adding symlink libcuda.so --> tegra/libcuda.so in target rootfs
Adding symlink libEGL.so --> libEGL.so.1 in target rootfs
Adding symlink /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs/usr/lib/aarch64-linux-gnu/libdrm_nvdc.so --> /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs/usr/lib/aarch64-linux-gnu/tegra/libdrm.so.2
Adding symlink nvidia_icd.json --> /etc/vulkan/icd.d/nvidia_icd.json in target rootfs
Adding symlinks for systemd nv.service and nvfb.service
Disabling NetworkManager-wait-online.service
Disable the ondemand service by changing the runlevels to 'K'
Extracting the firmwares and kernel modules to /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs
Extracting the kernel headers to /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs/usr/src
Adding symlink /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs/lib/modules/4.4.38-tegra/build --> /usr/src/linux-headers-4.4.38-tegra
Installing zImage into /boot in target rootfs
Installing Image into /boot in target rootfs
Installing the board *.dtb files into /boot in target rootfs
Success!
~/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/CTI-L4T
CTI-L4T-V110 Installed!
```

***
```sh
sudo ./flash.sh orbitty mmcblk0p1
```

```sh
chahatdeep@archahat:~/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2$ sudo ./flash.sh orbitty mmcblk0p1
./tegraflash.py --chip 0x18 --applet "/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/mb1_recovery_prod.bin" --cmd "dump eeprom boardinfo cvm.bin" --skipuid 
Welcome to Tegra Flash
version 1.0.0
Type ? or help for help and q or quit to exit
Use ! to execute system commands
 
[   0.0055 ] Generating RCM messages
[   0.0079 ] tegrarcm_v2 --listrcm rcm_list.xml --chip 0x18 --download rcm /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/mb1_recovery_prod.bin 0 0
[   0.0102 ] RCM 0 is saved as rcm_0.rcm
[   0.0244 ] RCM 1 is saved as rcm_1.rcm
[   0.0244 ] List of rcm files are saved in rcm_list.xml
[   0.0244 ] 
[   0.0245 ] Signing RCM messages
[   0.0417 ] tegrasign_v2 --key None --list rcm_list.xml --pubkeyhash pub_key.key
[   0.0440 ] Assuming zero filled SBK key
[   0.0511 ] 
[   0.0511 ] Copying signature to RCM mesages
[   0.0520 ] tegrarcm_v2 --chip 0x18 --updatesig rcm_list_signed.xml
[   0.0531 ] 
[   0.0531 ] Boot Rom communication
[   0.0540 ] tegrarcm_v2 --chip 0x18 --rcm rcm_list_signed.xml --skipuid
[   0.0548 ] RCM version 0X180001
[   0.0558 ] Boot Rom communication completed
[   1.0627 ] 
[   1.0651 ] tegrarcm_v2 --isapplet
[   1.0673 ] Applet version 01.00.0000
[   1.0815 ] 
[   1.0839 ] Retrieving EEPROM data
[   1.0841 ] tegrarcm_v2 --oem platformdetails eeprom cvm /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/cvm.bin
[   1.0862 ] Applet version 01.00.0000
[   1.1138 ] Saved platform info in /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/cvm.bin
[   1.1905 ] 
 
copying bctfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/P3310_A00_8GB_Samsung_8GB_lpddr4_204Mhz_A02_l4t.cfg)... done.
copying misc_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/tegra186-mb1-bct-misc-si-l4t.cfg)... done.
copying pinmux_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg)... done.
copying pmic_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg)... done.
copying pmc_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg)... done.
copying prod_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg)... done.
copying scr_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/minimal_scr.cfg)... done.
copying scr_cold_boot_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/mobile_scr.cfg)... done.
copying bootrom_config(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg)... done.
copying dev_params(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/BCT/emmc.cfg)... done.
Existing bootloader(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/nvtboot_cpu.bin) reused.
	populating kernel to rootfs... done.
	populating initrd to rootfs... done.
	populating extlinux.conf.emmc to rootfs... done.
	populating /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/kernel/dtb/tegra186-tx2-cti-ASG001-USB3.dtb to rootfs... done.
done.
Making Boot image... done.
Existing sosfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/mb1_recovery_prod.bin) reused.
copying tegraboot(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/nvtboot.bin)... done.
Existing mb2blfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/nvtboot_recovery.bin) reused.
Existing mtspreboot(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/preboot_d15_prod_cr.bin) reused.
Existing mts(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/mce_mts_d15_prod_cr.bin) reused.
Existing mb1file(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/mb1_prod.bin) reused.
Existing bpffile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/bpmp.bin) reused.
copying bpfdtbfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2.dtb)... done.
Existing scefile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/camera-rtcpu-sce.bin) reused.
Existing spefile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/spe.bin) reused.
copying wb0boot(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/warmboot.bin)... done.
Existing tosfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/tos.img) reused.
Existing eksfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/eks.img) reused.
copying dtbfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/kernel/dtb/tegra186-tx2-cti-ASG001-USB3.dtb)... done.
Making system.img... 
	populating rootfs from /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/rootfs ... 	done.
	Sync'ing system.img ... done.
	Converting RAW image to Sparse image... 

---- Raw to Sparse Image Converter v1.0 ----------------------------
  0: RAW:     4235264(   1034 blks) ==>          28:4235276
  1: SKP:       28672(      7 blks) ==>     4235304:12
  2: RAW:        4096(      1 blks) ==>     4235316:4108
  3: SKP:       61440(     15 blks) ==>     4239424:12
  4: RAW:        4096(      1 blks) ==>     4239436:4108
  5: SKP:    33550336(   8191 blks) ==>     4243544:12
  6: RAW:       24576(      6 blks) ==>     4243556:24588
  7: SKP:    96309248(  23513 blks) ==>     4268144:12
  8: RAW:       12288(      3 blks) ==>     4268156:12300
  9: SKP:     4186112(   1022 blks) ==>     4280456:12
 10: RAW:      622592(    152 blks) ==>     4280468:622604
 11: SKP:      667648(    163 blks) ==>     4903072:12
 12: RAW:       81920(     20 blks) ==>     4903084:81932
 13: SKP:       24576(      6 blks) ==>     4985016:12
 14: RAW:      135168(     33 blks) ==>     4985028:135180
 15: SKP:        8192(      2 blks) ==>     5120208:12
 16: RAW:        4096(      1 blks) ==>     5120220:4108
 17: SKP:       16384(      4 blks) ==>     5124328:12
 18: RAW:     1200128(    293 blks) ==>     5124340:1200140
 19: SKP:       16384(      4 blks) ==>     6324480:12
 20: RAW:        4096(      1 blks) ==>     6324492:4108
 21: SKP:       40960(     10 blks) ==>     6328600:12
 22: RAW:        4096(      1 blks) ==>     6328612:4108
 23: SKP:        8192(      2 blks) ==>     6332720:12
 24: RAW:      114688(     28 blks) ==>     6332732:114700
 25: SKP:        4096(      1 blks) ==>     6447432:12
 26: RAW:      573440(    140 blks) ==>     6447444:573452
 27: SKP:      663552(    162 blks) ==>     7020896:12
 28: RAW:    11554816(   2821 blks) ==>     7020908:11554828
 29: SKP:        4096(      1 blks) ==>    18575736:12
 30: RAW:        4096(      1 blks) ==>    18575748:4108
 31: SKP:        4096(      1 blks) ==>    18579856:12
 32: RAW:      630784(    154 blks) ==>    18579868:630796
 33: SKP:        4096(      1 blks) ==>    19210664:12
 34: RAW:    20135936(   4916 blks) ==>    19210676:20135948
 35: SKP:        4096(      1 blks) ==>    39346624:12
 36: RAW:       53248(     13 blks) ==>    39346636:53260
 37: SKP:        4096(      1 blks) ==>    39399896:12
 38: RAW:     8404992(   2052 blks) ==>    39399908:8405004
 39: SKP:     1138688(    278 blks) ==>    47804912:12
 40: RAW:      315392(     77 blks) ==>    47804924:315404
 41: SKP:        4096(      1 blks) ==>    48120328:12
 42: RAW:     3997696(    976 blks) ==>    48120340:3997708
 43: SKP:       69632(     17 blks) ==>    52118048:12
 44: RAW:       20480(      5 blks) ==>    52118060:20492
 45: SKP:        4096(      1 blks) ==>    52138552:12
 46: RAW:    19513344(   4764 blks) ==>    52138564:19513356
 47: SKP:        4096(      1 blks) ==>    71651920:12
 48: RAW:       53248(     13 blks) ==>    71651932:53260
 49: SKP:        4096(      1 blks) ==>    71705192:12
 50: RAW:     6823936(   1666 blks) ==>    71705204:6823948
 51: SKP:     2744320(    670 blks) ==>    78529152:12
 52: RAW:      315392(     77 blks) ==>    78529164:315404
 53: SKP:        4096(      1 blks) ==>    78844568:12
 54: RAW:     3989504(    974 blks) ==>    78844580:3989516
 55: SKP:       65536(     16 blks) ==>    82834096:12
 56: RAW:       20480(      5 blks) ==>    82834108:20492
 57: SKP:        4096(      1 blks) ==>    82854600:12
 58: RAW:    16187392(   3952 blks) ==>    82854612:16187404
 59: SKP:     4579328(   1118 blks) ==>    99042016:12
 60: RAW:    33198080(   8105 blks) ==>    99042028:33198092
 61: SKP:      356352(     87 blks) ==>   132240120:12
 62: RAW:    24981504(   6099 blks) ==>   132240132:24981516
 63: SKP:      184320(     45 blks) ==>   157221648:12
 64: RAW:    77180928(  18843 blks) ==>   157221660:77180940
 65: SKP:     6705152(   1637 blks) ==>   234402600:12
 66: RAW:    16789504(   4099 blks) ==>   234402612:16789516
 67: SKP:     8376320(   2045 blks) ==>   251192128:12
 68: RAW:    33198080(   8105 blks) ==>   251192140:33198092
 69: SKP:        4096(      1 blks) ==>   284390232:12
 70: RAW:    10960896(   2676 blks) ==>   284390244:10960908
 71: SKP:        4096(      1 blks) ==>   295351152:12
 72: RAW:       69632(     17 blks) ==>   295351164:69644
 73: SKP:        4096(      1 blks) ==>   295420808:12
 74: RAW:       16384(      4 blks) ==>   295420820:16396
 75: SKP:        4096(      1 blks) ==>   295437216:12
 76: RAW:       90112(     22 blks) ==>   295437228:90124
 77: SKP:        4096(      1 blks) ==>   295527352:12
 78: RAW:      221184(     54 blks) ==>   295527364:221196
 79: SKP:       12288(      3 blks) ==>   295748560:12
 80: RAW:      135168(     33 blks) ==>   295748572:135180
 81: SKP:       32768(      8 blks) ==>   295883752:12
 82: RAW:     1527808(    373 blks) ==>   295883764:1527820
 83: SKP:       12288(      3 blks) ==>   297411584:12
 84: RAW:        8192(      2 blks) ==>   297411596:8204
 85: SKP:        4096(      1 blks) ==>   297419800:12
 86: RAW:       28672(      7 blks) ==>   297419812:28684
 87: SKP:       12288(      3 blks) ==>   297448496:12
 88: RAW:       16384(      4 blks) ==>   297448508:16396
 89: SKP:        8192(      2 blks) ==>   297464904:12
 90: RAW:       40960(     10 blks) ==>   297464916:40972
 91: SKP:        4096(      1 blks) ==>   297505888:12
 92: RAW:        4096(      1 blks) ==>   297505900:4108
 93: SKP:        4096(      1 blks) ==>   297510008:12
 94: RAW:       45056(     11 blks) ==>   297510020:45068
 95: SKP:        4096(      1 blks) ==>   297555088:12
 96: RAW:        8192(      2 blks) ==>   297555100:8204
 97: SKP:        4096(      1 blks) ==>   297563304:12
 98: RAW:       98304(     24 blks) ==>   297563316:98316
 99: SKP:       16384(      4 blks) ==>   297661632:12
100: RAW:       16384(      4 blks) ==>   297661644:16396
101: SKP:       12288(      3 blks) ==>   297678040:12
102: RAW:        4096(      1 blks) ==>   297678052:4108
103: SKP:        8192(      2 blks) ==>   297682160:12
104: RAW:      356352(     87 blks) ==>   297682172:356364
105: SKP:        4096(      1 blks) ==>   298038536:12
106: RAW:        4096(      1 blks) ==>   298038548:4108
107: SKP:        4096(      1 blks) ==>   298042656:12
108: RAW:        4096(      1 blks) ==>   298042668:4108
109: SKP:        8192(      2 blks) ==>   298046776:12
110: RAW:       49152(     12 blks) ==>   298046788:49164
111: SKP:       12288(      3 blks) ==>   298095952:12
112: RAW:     1327104(    324 blks) ==>   298095964:1327116
113: SKP:       12288(      3 blks) ==>   299423080:12
114: RAW:      462848(    113 blks) ==>   299423092:462860
115: SKP:     1441792(    352 blks) ==>   299885952:12
116: RAW:    13467648(   3288 blks) ==>   299885964:13467660
117: SKP:     3309568(    808 blks) ==>   313353624:12
118: RAW:    26841088(   6553 blks) ==>   313353636:26841100
119: SKP:        4096(      1 blks) ==>   340194736:12
120: RAW:       40960(     10 blks) ==>   340194748:40972
121: SKP:        4096(      1 blks) ==>   340235720:12
122: RAW:      450560(    110 blks) ==>   340235732:450572
123: SKP:        4096(      1 blks) ==>   340686304:12
124: RAW:      434176(    106 blks) ==>   340686316:434188
125: SKP:        4096(      1 blks) ==>   341120504:12
126: RAW:      131072(     32 blks) ==>   341120516:131084
127: SKP:       16384(      4 blks) ==>   341251600:12
128: RAW:      122880(     30 blks) ==>   341251612:122892
129: SKP:        4096(      1 blks) ==>   341374504:12
130: RAW:      557056(    136 blks) ==>   341374516:557068
131: SKP:       36864(      9 blks) ==>   341931584:12
132: RAW:      651264(    159 blks) ==>   341931596:651276
133: SKP:        4096(      1 blks) ==>   342582872:12
134: RAW:       73728(     18 blks) ==>   342582884:73740
135: SKP:       73728(     18 blks) ==>   342656624:12
136: RAW:        4096(      1 blks) ==>   342656636:4108
137: SKP:        8192(      2 blks) ==>   342660744:12
138: RAW:        4096(      1 blks) ==>   342660756:4108
139: SKP:        4096(      1 blks) ==>   342664864:12
140: RAW:        4096(      1 blks) ==>   342664876:4108
141: SKP:        8192(      2 blks) ==>   342668984:12
142: RAW:       16384(      4 blks) ==>   342668996:16396
143: SKP:        4096(      1 blks) ==>   342685392:12
144: RAW:        4096(      1 blks) ==>   342685404:4108
145: SKP:        4096(      1 blks) ==>   342689512:12
146: RAW:        4096(      1 blks) ==>   342689524:4108
147: SKP:        4096(      1 blks) ==>   342693632:12
148: RAW:       12288(      3 blks) ==>   342693644:12300
149: SKP:        8192(      2 blks) ==>   342705944:12
150: RAW:       24576(      6 blks) ==>   342705956:24588
151: SKP:        4096(      1 blks) ==>   342730544:12
152: RAW:        8192(      2 blks) ==>   342730556:8204
153: SKP:        4096(      1 blks) ==>   342738760:12
154: RAW:        8192(      2 blks) ==>   342738772:8204
155: SKP:       12288(      3 blks) ==>   342746976:12
156: RAW:       16384(      4 blks) ==>   342746988:16396
157: SKP:        4096(      1 blks) ==>   342763384:12
158: RAW:        8192(      2 blks) ==>   342763396:8204
159: SKP:        4096(      1 blks) ==>   342771600:12
160: RAW:       73728(     18 blks) ==>   342771612:73740
161: SKP:       12288(      3 blks) ==>   342845352:12
162: RAW:        4096(      1 blks) ==>   342845364:4108
163: SKP:        8192(      2 blks) ==>   342849472:12
164: RAW:       24576(      6 blks) ==>   342849484:24588
165: SKP:        8192(      2 blks) ==>   342874072:12
166: RAW:       16384(      4 blks) ==>   342874084:16396
167: SKP:        4096(      1 blks) ==>   342890480:12
168: RAW:        4096(      1 blks) ==>   342890492:4108
169: SKP:       20480(      5 blks) ==>   342894600:12
170: RAW:        4096(      1 blks) ==>   342894612:4108
171: SKP:        8192(      2 blks) ==>   342898720:12
172: RAW:        4096(      1 blks) ==>   342898732:4108
173: SKP:        8192(      2 blks) ==>   342902840:12
174: RAW:        8192(      2 blks) ==>   342902852:8204
175: SKP:        4096(      1 blks) ==>   342911056:12
176: RAW:        4096(      1 blks) ==>   342911068:4108
177: SKP:       12288(      3 blks) ==>   342915176:12
178: RAW:        4096(      1 blks) ==>   342915188:4108
179: SKP:       45056(     11 blks) ==>   342919296:12
180: RAW:        8192(      2 blks) ==>   342919308:8204
181: SKP:       28672(      7 blks) ==>   342927512:12
182: RAW:        4096(      1 blks) ==>   342927524:4108
183: SKP:       40960(     10 blks) ==>   342931632:12
184: RAW:        4096(      1 blks) ==>   342931644:4108
185: SKP:       16384(      4 blks) ==>   342935752:12
186: RAW:       16384(      4 blks) ==>   342935764:16396
187: SKP:        8192(      2 blks) ==>   342952160:12
188: RAW:       53248(     13 blks) ==>   342952172:53260
189: SKP:       16384(      4 blks) ==>   343005432:12
190: RAW:        4096(      1 blks) ==>   343005444:4108
191: SKP:        8192(      2 blks) ==>   343009552:12
192: RAW:        8192(      2 blks) ==>   343009564:8204
193: SKP:        4096(      1 blks) ==>   343017768:12
194: RAW:      385024(     94 blks) ==>   343017780:385036
195: SKP:        4096(      1 blks) ==>   343402816:12
196: RAW:      241664(     59 blks) ==>   343402828:241676
197: SKP:       32768(      8 blks) ==>   343644504:12
198: RAW:      126976(     31 blks) ==>   343644516:126988
199: SKP:     2625536(    641 blks) ==>   343771504:12
200: RAW:    29159424(   7119 blks) ==>   343771516:29159436
201: SKP:       49152(     12 blks) ==>   372930952:12
202: RAW:        4096(      1 blks) ==>   372930964:4108
203: SKP:       61440(     15 blks) ==>   372935072:12
204: RAW:       20480(      5 blks) ==>   372935084:20492
205: SKP:       16384(      4 blks) ==>   372955576:12
206: RAW:     1720320(    420 blks) ==>   372955588:1720332
207: SKP:       45056(     11 blks) ==>   374675920:12
208: RAW:        4096(      1 blks) ==>   374675932:4108
209: SKP:      167936(     41 blks) ==>   374680040:12
210: RAW:      409600(    100 blks) ==>   374680052:409612
211: SKP:       45056(     11 blks) ==>   375089664:12
212: RAW:        4096(      1 blks) ==>   375089676:4108
213: SKP:      208896(     51 blks) ==>   375093784:12
214: RAW:      237568(     58 blks) ==>   375093796:237580
215: SKP:       86016(     21 blks) ==>   375331376:12
216: RAW:      294912(     72 blks) ==>   375331388:294924
217: SKP:       24576(      6 blks) ==>   375626312:12
218: RAW:        8192(      2 blks) ==>   375626324:8204
219: SKP:       86016(     21 blks) ==>   375634528:12
220: RAW:        4096(      1 blks) ==>   375634540:4108
221: SKP:       12288(      3 blks) ==>   375638648:12
222: RAW:        4096(      1 blks) ==>   375638660:4108
223: SKP:       57344(     14 blks) ==>   375642768:12
224: RAW:        8192(      2 blks) ==>   375642780:8204
225: SKP:       73728(     18 blks) ==>   375650984:12
226: RAW:        4096(      1 blks) ==>   375650996:4108
227: SKP:        4096(      1 blks) ==>   375655104:12
228: RAW:        8192(      2 blks) ==>   375655116:8204
229: SKP:       24576(      6 blks) ==>   375663320:12
230: RAW:       16384(      4 blks) ==>   375663332:16396
231: SKP:      684032(    167 blks) ==>   375679728:12
232: RAW:    29343744(   7164 blks) ==>   375679740:29343756
233: SKP:        4096(      1 blks) ==>   405023496:12
234: RAW:       40960(     10 blks) ==>   405023508:40972
235: SKP:       73728(     18 blks) ==>   405064480:12
236: RAW:        4096(      1 blks) ==>   405064492:4108
237: SKP:        8192(      2 blks) ==>   405068600:12
238: RAW:        4096(      1 blks) ==>   405068612:4108
239: SKP:        4096(      1 blks) ==>   405072720:12
240: RAW:        4096(      1 blks) ==>   405072732:4108
241: SKP:        8192(      2 blks) ==>   405076840:12
242: RAW:        4096(      1 blks) ==>   405076852:4108
243: SKP:        4096(      1 blks) ==>   405080960:12
244: RAW:       16384(      4 blks) ==>   405080972:16396
245: SKP:        4096(      1 blks) ==>   405097368:12
246: RAW:        4096(      1 blks) ==>   405097380:4108
247: SKP:        4096(      1 blks) ==>   405101488:12
248: RAW:       12288(      3 blks) ==>   405101500:12300
249: SKP:       12288(      3 blks) ==>   405113800:12
250: RAW:       20480(      5 blks) ==>   405113812:20492
251: SKP:        4096(      1 blks) ==>   405134304:12
252: RAW:        8192(      2 blks) ==>   405134316:8204
253: SKP:        8192(      2 blks) ==>   405142520:12
254: RAW:        4096(      1 blks) ==>   405142532:4108
255: SKP:       12288(      3 blks) ==>   405146640:12
256: RAW:       28672(      7 blks) ==>   405146652:28684
257: SKP:        4096(      1 blks) ==>   405175336:12
258: RAW:       73728(     18 blks) ==>   405175348:73740
259: SKP:       12288(      3 blks) ==>   405249088:12
260: RAW:        4096(      1 blks) ==>   405249100:4108
261: SKP:        8192(      2 blks) ==>   405253208:12
262: RAW:       16384(      4 blks) ==>   405253220:16396
263: SKP:        4096(      1 blks) ==>   405269616:12
264: RAW:        8192(      2 blks) ==>   405269628:8204
265: SKP:        4096(      1 blks) ==>   405277832:12
266: RAW:       16384(      4 blks) ==>   405277844:16396
267: SKP:        4096(      1 blks) ==>   405294240:12
268: RAW:        4096(      1 blks) ==>   405294252:4108
269: SKP:       20480(      5 blks) ==>   405298360:12
270: RAW:        4096(      1 blks) ==>   405298372:4108
271: SKP:        8192(      2 blks) ==>   405302480:12
272: RAW:        8192(      2 blks) ==>   405302492:8204
273: SKP:        8192(      2 blks) ==>   405310696:12
274: RAW:       12288(      3 blks) ==>   405310708:12300
275: SKP:       12288(      3 blks) ==>   405323008:12
276: RAW:        4096(      1 blks) ==>   405323020:4108
277: SKP:       45056(     11 blks) ==>   405327128:12
278: RAW:        8192(      2 blks) ==>   405327140:8204
279: SKP:       32768(      8 blks) ==>   405335344:12
280: RAW:        4096(      1 blks) ==>   405335356:4108
281: SKP:       36864(      9 blks) ==>   405339464:12
282: RAW:        4096(      1 blks) ==>   405339476:4108
283: SKP:       16384(      4 blks) ==>   405343584:12
284: RAW:       16384(      4 blks) ==>   405343596:16396
285: SKP:        8192(      2 blks) ==>   405359992:12
286: RAW:       53248(     13 blks) ==>   405360004:53260
287: SKP:       16384(      4 blks) ==>   405413264:12
288: RAW:        4096(      1 blks) ==>   405413276:4108
289: SKP:       12288(      3 blks) ==>   405417384:12
290: RAW:        4096(      1 blks) ==>   405417396:4108
291: SKP:        4096(      1 blks) ==>   405421504:12
292: RAW:       28672(      7 blks) ==>   405421516:28684
293: SKP:        4096(      1 blks) ==>   405450200:12
294: RAW:      352256(     86 blks) ==>   405450212:352268
295: SKP:        4096(      1 blks) ==>   405802480:12
296: RAW:      241664(     59 blks) ==>   405802492:241676
297: SKP:       36864(      9 blks) ==>   406044168:12
298: RAW:      167936(     41 blks) ==>   406044180:167948
299: SKP:       45056(     11 blks) ==>   406212128:12
300: RAW:        4096(      1 blks) ==>   406212140:4108
301: SKP:      208896(     51 blks) ==>   406216248:12
302: RAW:      299008(     73 blks) ==>   406216260:299020
303: SKP:       86016(     21 blks) ==>   406515280:12
304: RAW:      294912(     72 blks) ==>   406515292:294924
305: SKP:       24576(      6 blks) ==>   406810216:12
306: RAW:        8192(      2 blks) ==>   406810228:8204
307: SKP:       57344(     14 blks) ==>   406818432:12
308: RAW:        4096(      1 blks) ==>   406818444:4108
309: SKP:       12288(      3 blks) ==>   406822552:12
310: RAW:        4096(      1 blks) ==>   406822564:4108
311: SKP:       40960(     10 blks) ==>   406826672:12
312: RAW:        8192(      2 blks) ==>   406826684:8204
313: SKP:       57344(     14 blks) ==>   406834888:12
314: RAW:       12288(      3 blks) ==>   406834900:12300
315: SKP:       28672(      7 blks) ==>   406847200:12
316: RAW:       16384(      4 blks) ==>   406847212:16396
317: SKP:     1359872(    332 blks) ==>   406863608:12
318: RAW:     4972544(   1214 blks) ==>   406863620:4972556
319: SKP:       16384(      4 blks) ==>   411836176:12
320: RAW:        8192(      2 blks) ==>   411836188:8204
321: SKP:       16384(      4 blks) ==>   411844392:12
322: RAW:       32768(      8 blks) ==>   411844404:32780
323: SKP:        4096(      1 blks) ==>   411877184:12
324: RAW:        4096(      1 blks) ==>   411877196:4108
325: SKP:       12288(      3 blks) ==>   411881304:12
326: RAW:        8192(      2 blks) ==>   411881316:8204
327: SKP:       12288(      3 blks) ==>   411889520:12
328: RAW:        8192(      2 blks) ==>   411889532:8204
329: SKP:        8192(      2 blks) ==>   411897736:12
330: RAW:       28672(      7 blks) ==>   411897748:28684
331: SKP:        4096(      1 blks) ==>   411926432:12
332: RAW:        4096(      1 blks) ==>   411926444:4108
333: SKP:       12288(      3 blks) ==>   411930552:12
334: RAW:        8192(      2 blks) ==>   411930564:8204
335: SKP:       12288(      3 blks) ==>   411938768:12
336: RAW:       32768(      8 blks) ==>   411938780:32780
337: SKP:       12288(      3 blks) ==>   411971560:12
338: RAW:        8192(      2 blks) ==>   411971572:8204
339: SKP:       12288(      3 blks) ==>   411979776:12
340: RAW:        4096(      1 blks) ==>   411979788:4108
341: SKP:       12288(      3 blks) ==>   411983896:12
342: RAW:        8192(      2 blks) ==>   411983908:8204
343: SKP:       12288(      3 blks) ==>   411992112:12
344: RAW:        8192(      2 blks) ==>   411992124:8204
345: SKP:       12288(      3 blks) ==>   412000328:12
346: RAW:        4096(      1 blks) ==>   412000340:4108
347: SKP:       12288(      3 blks) ==>   412004448:12
348: RAW:        8192(      2 blks) ==>   412004460:8204
349: SKP:       12288(      3 blks) ==>   412012664:12
350: RAW:        8192(      2 blks) ==>   412012676:8204
351: SKP:       12288(      3 blks) ==>   412020880:12
352: RAW:        4096(      1 blks) ==>   412020892:4108
353: SKP:       12288(      3 blks) ==>   412025000:12
354: RAW:        8192(      2 blks) ==>   412025012:8204
355: SKP:       12288(      3 blks) ==>   412033216:12
356: RAW:        8192(      2 blks) ==>   412033228:8204
357: SKP:       12288(      3 blks) ==>   412041432:12
358: RAW:        4096(      1 blks) ==>   412041444:4108
359: SKP:       12288(      3 blks) ==>   412045552:12
360: RAW:        8192(      2 blks) ==>   412045564:8204
361: SKP:       12288(      3 blks) ==>   412053768:12
362: RAW:        8192(      2 blks) ==>   412053780:8204
363: SKP:       12288(      3 blks) ==>   412061984:12
364: RAW:        4096(      1 blks) ==>   412061996:4108
365: SKP:       12288(      3 blks) ==>   412066104:12
366: RAW:        8192(      2 blks) ==>   412066116:8204
367: SKP:       12288(      3 blks) ==>   412074320:12
368: RAW:        4096(      1 blks) ==>   412074332:4108
369: SKP:       12288(      3 blks) ==>   412078440:12
370: RAW:        8192(      2 blks) ==>   412078452:8204
371: SKP:       12288(      3 blks) ==>   412086656:12
372: RAW:        4096(      1 blks) ==>   412086668:4108
373: SKP:       12288(      3 blks) ==>   412090776:12
374: RAW:        8192(      2 blks) ==>   412090788:8204
375: SKP:       12288(      3 blks) ==>   412098992:12
376: RAW:        4096(      1 blks) ==>   412099004:4108
377: SKP:       12288(      3 blks) ==>   412103112:12
378: RAW:        8192(      2 blks) ==>   412103124:8204
379: SKP:       12288(      3 blks) ==>   412111328:12
380: RAW:        8192(      2 blks) ==>   412111340:8204
381: SKP:        8192(      2 blks) ==>   412119544:12
382: RAW:        8192(      2 blks) ==>   412119556:8204
383: SKP:        4096(      1 blks) ==>   412127760:12
384: RAW:        4096(      1 blks) ==>   412127772:4108
385: SKP:       16384(      4 blks) ==>   412131880:12
386: RAW:       16384(      4 blks) ==>   412131892:16396
387: SKP:       12288(      3 blks) ==>   412148288:12
388: RAW:        8192(      2 blks) ==>   412148300:8204
389: SKP:        4096(      1 blks) ==>   412156504:12
390: RAW:        8192(      2 blks) ==>   412156516:8204
391: SKP:       12288(      3 blks) ==>   412164720:12
392: RAW:       12288(      3 blks) ==>   412164732:12300
393: SKP:       12288(      3 blks) ==>   412177032:12
394: RAW:        8192(      2 blks) ==>   412177044:8204
395: SKP:       12288(      3 blks) ==>   412185248:12
396: RAW:        8192(      2 blks) ==>   412185260:8204
397: SKP:       12288(      3 blks) ==>   412193464:12
398: RAW:        8192(      2 blks) ==>   412193476:8204
399: SKP:       12288(      3 blks) ==>   412201680:12
400: RAW:        8192(      2 blks) ==>   412201692:8204
401: SKP:       12288(      3 blks) ==>   412209896:12
402: RAW:        4096(      1 blks) ==>   412209908:4108
403: SKP:       12288(      3 blks) ==>   412214016:12
404: RAW:        8192(      2 blks) ==>   412214028:8204
405: SKP:       12288(      3 blks) ==>   412222232:12
406: RAW:        8192(      2 blks) ==>   412222244:8204
407: SKP:       12288(      3 blks) ==>   412230448:12
408: RAW:        4096(      1 blks) ==>   412230460:4108
409: SKP:       12288(      3 blks) ==>   412234568:12
410: RAW:        8192(      2 blks) ==>   412234580:8204
411: SKP:       12288(      3 blks) ==>   412242784:12
412: RAW:        4096(      1 blks) ==>   412242796:4108
413: SKP:       12288(      3 blks) ==>   412246904:12
414: RAW:        8192(      2 blks) ==>   412246916:8204
415: SKP:       12288(      3 blks) ==>   412255120:12
416: RAW:        8192(      2 blks) ==>   412255132:8204
417: SKP:        8192(      2 blks) ==>   412263336:12
418: RAW:        8192(      2 blks) ==>   412263348:8204
419: SKP:       12288(      3 blks) ==>   412271552:12
420: RAW:        8192(      2 blks) ==>   412271564:8204
421: SKP:       12288(      3 blks) ==>   412279768:12
422: RAW:        4096(      1 blks) ==>   412279780:4108
423: SKP:       12288(      3 blks) ==>   412283888:12
424: RAW:        8192(      2 blks) ==>   412283900:8204
425: SKP:       12288(      3 blks) ==>   412292104:12
426: RAW:        4096(      1 blks) ==>   412292116:4108
427: SKP:       12288(      3 blks) ==>   412296224:12
428: RAW:        8192(      2 blks) ==>   412296236:8204
429: SKP:       12288(      3 blks) ==>   412304440:12
430: RAW:        4096(      1 blks) ==>   412304452:4108
431: SKP:       12288(      3 blks) ==>   412308560:12
432: RAW:        8192(      2 blks) ==>   412308572:8204
433: SKP:       12288(      3 blks) ==>   412316776:12
434: RAW:        4096(      1 blks) ==>   412316788:4108
435: SKP:       12288(      3 blks) ==>   412320896:12
436: RAW:        8192(      2 blks) ==>   412320908:8204
437: SKP:       12288(      3 blks) ==>   412329112:12
438: RAW:        8192(      2 blks) ==>   412329124:8204
439: SKP:       12288(      3 blks) ==>   412337328:12
440: RAW:        4096(      1 blks) ==>   412337340:4108
441: SKP:       12288(      3 blks) ==>   412341448:12
442: RAW:        8192(      2 blks) ==>   412341460:8204
443: SKP:       12288(      3 blks) ==>   412349664:12
444: RAW:        4096(      1 blks) ==>   412349676:4108
445: SKP:       12288(      3 blks) ==>   412353784:12
446: RAW:        4096(      1 blks) ==>   412353796:4108
447: SKP:        4096(      1 blks) ==>   412357904:12
448: RAW:        4096(      1 blks) ==>   412357916:4108
449: SKP:       12288(      3 blks) ==>   412362024:12
450: RAW:        4096(      1 blks) ==>   412362036:4108
451: SKP:       12288(      3 blks) ==>   412366144:12
452: RAW:        8192(      2 blks) ==>   412366156:8204
453: SKP:       12288(      3 blks) ==>   412374360:12
454: RAW:        8192(      2 blks) ==>   412374372:8204
455: SKP:       12288(      3 blks) ==>   412382576:12
456: RAW:        4096(      1 blks) ==>   412382588:4108
457: SKP:       12288(      3 blks) ==>   412386696:12
458: RAW:        8192(      2 blks) ==>   412386708:8204
459: SKP:       12288(      3 blks) ==>   412394912:12
460: RAW:        8192(      2 blks) ==>   412394924:8204
461: SKP:       12288(      3 blks) ==>   412403128:12
462: RAW:        4096(      1 blks) ==>   412403140:4108
463: SKP:       12288(      3 blks) ==>   412407248:12
464: RAW:        8192(      2 blks) ==>   412407260:8204
465: SKP:       12288(      3 blks) ==>   412415464:12
466: RAW:        8192(      2 blks) ==>   412415476:8204
467: SKP:        8192(      2 blks) ==>   412423680:12
468: RAW:        8192(      2 blks) ==>   412423692:8204
469: SKP:       12288(      3 blks) ==>   412431896:12
470: RAW:        8192(      2 blks) ==>   412431908:8204
471: SKP:       12288(      3 blks) ==>   412440112:12
472: RAW:        8192(      2 blks) ==>   412440124:8204
473: SKP:       12288(      3 blks) ==>   412448328:12
474: RAW:        4096(      1 blks) ==>   412448340:4108
475: SKP:       12288(      3 blks) ==>   412452448:12
476: RAW:        8192(      2 blks) ==>   412452460:8204
477: SKP:       12288(      3 blks) ==>   412460664:12
478: RAW:        4096(      1 blks) ==>   412460676:4108
479: SKP:       12288(      3 blks) ==>   412464784:12
480: RAW:       12288(      3 blks) ==>   412464796:12300
481: SKP:       12288(      3 blks) ==>   412477096:12
482: RAW:        8192(      2 blks) ==>   412477108:8204
483: SKP:       12288(      3 blks) ==>   412485312:12
484: RAW:       12288(      3 blks) ==>   412485324:12300
485: SKP:       12288(      3 blks) ==>   412497624:12
486: RAW:        8192(      2 blks) ==>   412497636:8204
487: SKP:       12288(      3 blks) ==>   412505840:12
488: RAW:        8192(      2 blks) ==>   412505852:8204
489: SKP:       12288(      3 blks) ==>   412514056:12
490: RAW:        4096(      1 blks) ==>   412514068:4108
491: SKP:       12288(      3 blks) ==>   412518176:12
492: RAW:        8192(      2 blks) ==>   412518188:8204
493: SKP:       12288(      3 blks) ==>   412526392:12
494: RAW:        8192(      2 blks) ==>   412526404:8204
495: SKP:        8192(      2 blks) ==>   412534608:12
496: RAW:        8192(      2 blks) ==>   412534620:8204
497: SKP:       12288(      3 blks) ==>   412542824:12
498: RAW:       12288(      3 blks) ==>   412542836:12300
499: SKP:       12288(      3 blks) ==>   412555136:12
500: RAW:       12288(      3 blks) ==>   412555148:12300
501: SKP:       12288(      3 blks) ==>   412567448:12
502: RAW:        8192(      2 blks) ==>   412567460:8204
503: SKP:       12288(      3 blks) ==>   412575664:12
504: RAW:        4096(      1 blks) ==>   412575676:4108
505: SKP:       12288(      3 blks) ==>   412579784:12
506: RAW:        8192(      2 blks) ==>   412579796:8204
507: SKP:       12288(      3 blks) ==>   412588000:12
508: RAW:        8192(      2 blks) ==>   412588012:8204
509: SKP:       12288(      3 blks) ==>   412596216:12
510: RAW:        4096(      1 blks) ==>   412596228:4108
511: SKP:       12288(      3 blks) ==>   412600336:12
512: RAW:        8192(      2 blks) ==>   412600348:8204
513: SKP:       12288(      3 blks) ==>   412608552:12
514: RAW:        8192(      2 blks) ==>   412608564:8204
515: SKP:       12288(      3 blks) ==>   412616768:12
516: RAW:       12288(      3 blks) ==>   412616780:12300
517: SKP:       12288(      3 blks) ==>   412629080:12
518: RAW:        8192(      2 blks) ==>   412629092:8204
519: SKP:       12288(      3 blks) ==>   412637296:12
520: RAW:        8192(      2 blks) ==>   412637308:8204
521: SKP:        4096(      1 blks) ==>   412645512:12
522: RAW:        8192(      2 blks) ==>   412645524:8204
523: SKP:        8192(      2 blks) ==>   412653728:12
524: RAW:        8192(      2 blks) ==>   412653740:8204
525: SKP:       12288(      3 blks) ==>   412661944:12
526: RAW:        8192(      2 blks) ==>   412661956:8204
527: SKP:       12288(      3 blks) ==>   412670160:12
528: RAW:        4096(      1 blks) ==>   412670172:4108
529: SKP:       12288(      3 blks) ==>   412674280:12
530: RAW:        8192(      2 blks) ==>   412674292:8204
531: SKP:       12288(      3 blks) ==>   412682496:12
532: RAW:        4096(      1 blks) ==>   412682508:4108
533: SKP:       12288(      3 blks) ==>   412686616:12
534: RAW:        8192(      2 blks) ==>   412686628:8204
535: SKP:       12288(      3 blks) ==>   412694832:12
536: RAW:        4096(      1 blks) ==>   412694844:4108
537: SKP:       12288(      3 blks) ==>   412698952:12
538: RAW:        8192(      2 blks) ==>   412698964:8204
539: SKP:       12288(      3 blks) ==>   412707168:12
540: RAW:        4096(      1 blks) ==>   412707180:4108
541: SKP:       12288(      3 blks) ==>   412711288:12
542: RAW:        8192(      2 blks) ==>   412711300:8204
543: SKP:       12288(      3 blks) ==>   412719504:12
544: RAW:        4096(      1 blks) ==>   412719516:4108
545: SKP:       12288(      3 blks) ==>   412723624:12
546: RAW:        8192(      2 blks) ==>   412723636:8204
547: SKP:       12288(      3 blks) ==>   412731840:12
548: RAW:        4096(      1 blks) ==>   412731852:4108
549: SKP:       12288(      3 blks) ==>   412735960:12
550: RAW:        8192(      2 blks) ==>   412735972:8204
551: SKP:        4096(      1 blks) ==>   412744176:12
552: RAW:        4096(      1 blks) ==>   412744188:4108
553: SKP:       12288(      3 blks) ==>   412748296:12
554: RAW:        4096(      1 blks) ==>   412748308:4108
555: SKP:        4096(      1 blks) ==>   412752416:12
556: RAW:        4096(      1 blks) ==>   412752428:4108
557: SKP:       12288(      3 blks) ==>   412756536:12
558: RAW:       16384(      4 blks) ==>   412756548:16396
559: SKP:       12288(      3 blks) ==>   412772944:12
560: RAW:        4096(      1 blks) ==>   412772956:4108
561: SKP:        4096(      1 blks) ==>   412777064:12
562: RAW:        4096(      1 blks) ==>   412777076:4108
563: SKP:       12288(      3 blks) ==>   412781184:12
564: RAW:        8192(      2 blks) ==>   412781196:8204
565: SKP:       12288(      3 blks) ==>   412789400:12
566: RAW:        4096(      1 blks) ==>   412789412:4108
567: SKP:       12288(      3 blks) ==>   412793520:12
568: RAW:        8192(      2 blks) ==>   412793532:8204
569: SKP:       12288(      3 blks) ==>   412801736:12
570: RAW:        4096(      1 blks) ==>   412801748:4108
571: SKP:       12288(      3 blks) ==>   412805856:12
572: RAW:        8192(      2 blks) ==>   412805868:8204
573: SKP:       12288(      3 blks) ==>   412814072:12
574: RAW:        8192(      2 blks) ==>   412814084:8204
575: SKP:        8192(      2 blks) ==>   412822288:12
576: RAW:       12288(      3 blks) ==>   412822300:12300
577: SKP:       12288(      3 blks) ==>   412834600:12
578: RAW:        8192(      2 blks) ==>   412834612:8204
579: SKP:       12288(      3 blks) ==>   412842816:12
580: RAW:        4096(      1 blks) ==>   412842828:4108
581: SKP:       12288(      3 blks) ==>   412846936:12
582: RAW:        8192(      2 blks) ==>   412846948:8204
583: SKP:       12288(      3 blks) ==>   412855152:12
584: RAW:        4096(      1 blks) ==>   412855164:4108
585: SKP:       12288(      3 blks) ==>   412859272:12
586: RAW:        8192(      2 blks) ==>   412859284:8204
587: SKP:       12288(      3 blks) ==>   412867488:12
588: RAW:        4096(      1 blks) ==>   412867500:4108
589: SKP:       12288(      3 blks) ==>   412871608:12
590: RAW:        8192(      2 blks) ==>   412871620:8204
591: SKP:       12288(      3 blks) ==>   412879824:12
592: RAW:        4096(      1 blks) ==>   412879836:4108
593: SKP:       12288(      3 blks) ==>   412883944:12
594: RAW:        8192(      2 blks) ==>   412883956:8204
595: SKP:       12288(      3 blks) ==>   412892160:12
596: RAW:        4096(      1 blks) ==>   412892172:4108
597: SKP:       12288(      3 blks) ==>   412896280:12
598: RAW:        8192(      2 blks) ==>   412896292:8204
599: SKP:       12288(      3 blks) ==>   412904496:12
600: RAW:        4096(      1 blks) ==>   412904508:4108
601: SKP:       12288(      3 blks) ==>   412908616:12
602: RAW:        8192(      2 blks) ==>   412908628:8204
603: SKP:       12288(      3 blks) ==>   412916832:12
604: RAW:        8192(      2 blks) ==>   412916844:8204
605: SKP:        8192(      2 blks) ==>   412925048:12
606: RAW:        8192(      2 blks) ==>   412925060:8204
607: SKP:       12288(      3 blks) ==>   412933264:12
608: RAW:        8192(      2 blks) ==>   412933276:8204
609: SKP:       12288(      3 blks) ==>   412941480:12
610: RAW:        4096(      1 blks) ==>   412941492:4108
611: SKP:       12288(      3 blks) ==>   412945600:12
612: RAW:        8192(      2 blks) ==>   412945612:8204
613: SKP:       12288(      3 blks) ==>   412953816:12
614: RAW:        4096(      1 blks) ==>   412953828:4108
615: SKP:       12288(      3 blks) ==>   412957936:12
616: RAW:        8192(      2 blks) ==>   412957948:8204
617: SKP:       12288(      3 blks) ==>   412966152:12
618: RAW:        4096(      1 blks) ==>   412966164:4108
619: SKP:       12288(      3 blks) ==>   412970272:12
620: RAW:        8192(      2 blks) ==>   412970284:8204
621: SKP:       12288(      3 blks) ==>   412978488:12
622: RAW:        4096(      1 blks) ==>   412978500:4108
623: SKP:       12288(      3 blks) ==>   412982608:12
624: RAW:        8192(      2 blks) ==>   412982620:8204
625: SKP:       12288(      3 blks) ==>   412990824:12
626: RAW:        4096(      1 blks) ==>   412990836:4108
627: SKP:       12288(      3 blks) ==>   412994944:12
628: RAW:        8192(      2 blks) ==>   412994956:8204
629: SKP:       12288(      3 blks) ==>   413003160:12
630: RAW:        8192(      2 blks) ==>   413003172:8204
631: SKP:       12288(      3 blks) ==>   413011376:12
632: RAW:        4096(      1 blks) ==>   413011388:4108
633: SKP:       12288(      3 blks) ==>   413015496:12
634: RAW:        8192(      2 blks) ==>   413015508:8204
635: SKP:       12288(      3 blks) ==>   413023712:12
636: RAW:        8192(      2 blks) ==>   413023724:8204
637: SKP:       12288(      3 blks) ==>   413031928:12
638: RAW:        4096(      1 blks) ==>   413031940:4108
639: SKP:       12288(      3 blks) ==>   413036048:12
640: RAW:        8192(      2 blks) ==>   413036060:8204
641: SKP:       12288(      3 blks) ==>   413044264:12
642: RAW:        4096(      1 blks) ==>   413044276:4108
643: SKP:       12288(      3 blks) ==>   413048384:12
644: RAW:        8192(      2 blks) ==>   413048396:8204
645: SKP:       12288(      3 blks) ==>   413056600:12
646: RAW:        8192(      2 blks) ==>   413056612:8204
647: SKP:        8192(      2 blks) ==>   413064816:12
648: RAW:        8192(      2 blks) ==>   413064828:8204
649: SKP:       12288(      3 blks) ==>   413073032:12
650: RAW:        8192(      2 blks) ==>   413073044:8204
651: SKP:       12288(      3 blks) ==>   413081248:12
652: RAW:        4096(      1 blks) ==>   413081260:4108
653: SKP:       12288(      3 blks) ==>   413085368:12
654: RAW:        8192(      2 blks) ==>   413085380:8204
655: SKP:       12288(      3 blks) ==>   413093584:12
656: RAW:        4096(      1 blks) ==>   413093596:4108
657: SKP:       12288(      3 blks) ==>   413097704:12
658: RAW:        8192(      2 blks) ==>   413097716:8204
659: SKP:        4096(      1 blks) ==>   413105920:12
660: RAW:        4096(      1 blks) ==>   413105932:4108
661: SKP:       12288(      3 blks) ==>   413110040:12
662: RAW:        8192(      2 blks) ==>   413110052:8204
663: SKP:       12288(      3 blks) ==>   413118256:12
664: RAW:        4096(      1 blks) ==>   413118268:4108
665: SKP:       12288(      3 blks) ==>   413122376:12
666: RAW:        4096(      1 blks) ==>   413122388:4108
667: SKP:       12288(      3 blks) ==>   413126496:12
668: RAW:       12288(      3 blks) ==>   413126508:12300
669: SKP:       12288(      3 blks) ==>   413138808:12
670: RAW:        4096(      1 blks) ==>   413138820:4108
671: SKP:       12288(      3 blks) ==>   413142928:12
672: RAW:        8192(      2 blks) ==>   413142940:8204
673: SKP:       12288(      3 blks) ==>   413151144:12
674: RAW:        4096(      1 blks) ==>   413151156:4108
675: SKP:       12288(      3 blks) ==>   413155264:12
676: RAW:        8192(      2 blks) ==>   413155276:8204
677: SKP:       12288(      3 blks) ==>   413163480:12
678: RAW:        8192(      2 blks) ==>   413163492:8204
679: SKP:       12288(      3 blks) ==>   413171696:12
680: RAW:        4096(      1 blks) ==>   413171708:4108
681: SKP:       12288(      3 blks) ==>   413175816:12
682: RAW:        8192(      2 blks) ==>   413175828:8204
683: SKP:       12288(      3 blks) ==>   413184032:12
684: RAW:        8192(      2 blks) ==>   413184044:8204
685: SKP:       12288(      3 blks) ==>   413192248:12
686: RAW:        4096(      1 blks) ==>   413192260:4108
687: SKP:       12288(      3 blks) ==>   413196368:12
688: RAW:        8192(      2 blks) ==>   413196380:8204
689: SKP:       12288(      3 blks) ==>   413204584:12
690: RAW:        8192(      2 blks) ==>   413204596:8204
691: SKP:       12288(      3 blks) ==>   413212800:12
692: RAW:      122880(     30 blks) ==>   413212812:122892
693: SKP:       12288(      3 blks) ==>   413335704:12
694: RAW:        8192(      2 blks) ==>   413335716:8204
695: SKP:       12288(      3 blks) ==>   413343920:12
696: RAW:        4096(      1 blks) ==>   413343932:4108
697: SKP:       12288(      3 blks) ==>   413348040:12
698: RAW:        8192(      2 blks) ==>   413348052:8204
699: SKP:       24576(      6 blks) ==>   413356256:12
700: RAW:       73728(     18 blks) ==>   413356268:73740
701: SKP:       12288(      3 blks) ==>   413430008:12
702: RAW:        8192(      2 blks) ==>   413430020:8204
703: SKP:       12288(      3 blks) ==>   413438224:12
704: RAW:        8192(      2 blks) ==>   413438236:8204
705: SKP:       12288(      3 blks) ==>   413446440:12
706: RAW:        4096(      1 blks) ==>   413446452:4108
707: SKP:       12288(      3 blks) ==>   413450560:12
708: RAW:       12288(      3 blks) ==>   413450572:12300
709: SKP:        8192(      2 blks) ==>   413462872:12
710: RAW:       12288(      3 blks) ==>   413462884:12300
711: SKP:       12288(      3 blks) ==>   413475184:12
712: RAW:        8192(      2 blks) ==>   413475196:8204
713: SKP:       12288(      3 blks) ==>   413483400:12
714: RAW:        8192(      2 blks) ==>   413483412:8204
715: SKP:       12288(      3 blks) ==>   413491616:12
716: RAW:        8192(      2 blks) ==>   413491628:8204
717: SKP:       12288(      3 blks) ==>   413499832:12
718: RAW:        4096(      1 blks) ==>   413499844:4108
719: SKP:        4096(      1 blks) ==>   413503952:12
720: RAW:        4096(      1 blks) ==>   413503964:4108
721: SKP:       12288(      3 blks) ==>   413508072:12
722: RAW:        4096(      1 blks) ==>   413508084:4108
723: SKP:        8192(      2 blks) ==>   413512192:12
724: RAW:        4096(      1 blks) ==>   413512204:4108
725: SKP:        4096(      1 blks) ==>   413516312:12
726: RAW:        4096(      1 blks) ==>   413516324:4108
727: SKP:        4096(      1 blks) ==>   413520432:12
728: RAW:       16384(      4 blks) ==>   413520444:16396
729: SKP:        4096(      1 blks) ==>   413536840:12
730: RAW:        4096(      1 blks) ==>   413536852:4108
731: SKP:        4096(      1 blks) ==>   413540960:12
732: RAW:        4096(      1 blks) ==>   413540972:4108
733: SKP:        8192(      2 blks) ==>   413545080:12
734: RAW:       12288(      3 blks) ==>   413545092:12300
735: SKP:        4096(      1 blks) ==>   413557392:12
736: RAW:        4096(      1 blks) ==>   413557404:4108
737: SKP:        4096(      1 blks) ==>   413561512:12
738: RAW:        4096(      1 blks) ==>   413561524:4108
739: SKP:        8192(      2 blks) ==>   413565632:12
740: RAW:        4096(      1 blks) ==>   413565644:4108
741: SKP:        4096(      1 blks) ==>   413569752:12
742: RAW:        4096(      1 blks) ==>   413569764:4108
743: SKP:        4096(      1 blks) ==>   413573872:12
744: RAW:       16384(      4 blks) ==>   413573884:16396
745: SKP:        4096(      1 blks) ==>   413590280:12
746: RAW:        4096(      1 blks) ==>   413590292:4108
747: SKP:        4096(      1 blks) ==>   413594400:12
748: RAW:        4096(      1 blks) ==>   413594412:4108
749: SKP:        4096(      1 blks) ==>   413598520:12
750: RAW:       16384(      4 blks) ==>   413598532:16396
751: SKP:        4096(      1 blks) ==>   413614928:12
752: RAW:        4096(      1 blks) ==>   413614940:4108
753: SKP:        4096(      1 blks) ==>   413619048:12
754: RAW:        4096(      1 blks) ==>   413619060:4108
755: SKP:        8192(      2 blks) ==>   413623168:12
756: RAW:       12288(      3 blks) ==>   413623180:12300
757: SKP:        4096(      1 blks) ==>   413635480:12
758: RAW:        4096(      1 blks) ==>   413635492:4108
759: SKP:        4096(      1 blks) ==>   413639600:12
760: RAW:        4096(      1 blks) ==>   413639612:4108
761: SKP:        8192(      2 blks) ==>   413643720:12
762: RAW:        4096(      1 blks) ==>   413643732:4108
763: SKP:        4096(      1 blks) ==>   413647840:12
764: RAW:        4096(      1 blks) ==>   413647852:4108
765: SKP:        4096(      1 blks) ==>   413651960:12
766: RAW:       12288(      3 blks) ==>   413651972:12300
767: SKP:        8192(      2 blks) ==>   413664272:12
768: RAW:        4096(      1 blks) ==>   413664284:4108
769: SKP:        4096(      1 blks) ==>   413668392:12
770: RAW:        4096(      1 blks) ==>   413668404:4108
771: SKP:        4096(      1 blks) ==>   413672512:12
772: RAW:       16384(      4 blks) ==>   413672524:16396
773: SKP:        4096(      1 blks) ==>   413688920:12
774: RAW:        4096(      1 blks) ==>   413688932:4108
775: SKP:        4096(      1 blks) ==>   413693040:12
776: RAW:        4096(      1 blks) ==>   413693052:4108
777: SKP:        8192(      2 blks) ==>   413697160:12
778: RAW:       12288(      3 blks) ==>   413697172:12300
779: SKP:        4096(      1 blks) ==>   413709472:12
780: RAW:        4096(      1 blks) ==>   413709484:4108
781: SKP:        4096(      1 blks) ==>   413713592:12
782: RAW:        4096(      1 blks) ==>   413713604:4108
783: SKP:        8192(      2 blks) ==>   413717712:12
784: RAW:       12288(      3 blks) ==>   413717724:12300
785: SKP:        4096(      1 blks) ==>   413730024:12
786: RAW:        4096(      1 blks) ==>   413730036:4108
787: SKP:        4096(      1 blks) ==>   413734144:12
788: RAW:        4096(      1 blks) ==>   413734156:4108
789: SKP:        8192(      2 blks) ==>   413738264:12
790: RAW:        4096(      1 blks) ==>   413738276:4108
791: SKP:        4096(      1 blks) ==>   413742384:12
792: RAW:        4096(      1 blks) ==>   413742396:4108
793: SKP:        4096(      1 blks) ==>   413746504:12
794: RAW:       16384(      4 blks) ==>   413746516:16396
795: SKP:        4096(      1 blks) ==>   413762912:12
796: RAW:        4096(      1 blks) ==>   413762924:4108
797: SKP:        4096(      1 blks) ==>   413767032:12
798: RAW:        4096(      1 blks) ==>   413767044:4108
799: SKP:        4096(      1 blks) ==>   413771152:12
800: RAW:       16384(      4 blks) ==>   413771164:16396
801: SKP:        4096(      1 blks) ==>   413787560:12
802: RAW:        4096(      1 blks) ==>   413787572:4108
803: SKP:        4096(      1 blks) ==>   413791680:12
804: RAW:        4096(      1 blks) ==>   413791692:4108
805: SKP:        8192(      2 blks) ==>   413795800:12
806: RAW:       12288(      3 blks) ==>   413795812:12300
807: SKP:        4096(      1 blks) ==>   413808112:12
808: RAW:        4096(      1 blks) ==>   413808124:4108
809: SKP:        4096(      1 blks) ==>   413812232:12
810: RAW:        4096(      1 blks) ==>   413812244:4108
811: SKP:        8192(      2 blks) ==>   413816352:12
812: RAW:        4096(      1 blks) ==>   413816364:4108
813: SKP:        4096(      1 blks) ==>   413820472:12
814: RAW:        4096(      1 blks) ==>   413820484:4108
815: SKP:        4096(      1 blks) ==>   413824592:12
816: RAW:       12288(      3 blks) ==>   413824604:12300
817: SKP:        8192(      2 blks) ==>   413836904:12
818: RAW:        4096(      1 blks) ==>   413836916:4108
819: SKP:        4096(      1 blks) ==>   413841024:12
820: RAW:        4096(      1 blks) ==>   413841036:4108
821: SKP:        4096(      1 blks) ==>   413845144:12
822: RAW:       16384(      4 blks) ==>   413845156:16396
823: SKP:        4096(      1 blks) ==>   413861552:12
824: RAW:        4096(      1 blks) ==>   413861564:4108
825: SKP:        4096(      1 blks) ==>   413865672:12
826: RAW:        4096(      1 blks) ==>   413865684:4108
827: SKP:        8192(      2 blks) ==>   413869792:12
828: RAW:       12288(      3 blks) ==>   413869804:12300
829: SKP:        4096(      1 blks) ==>   413882104:12
830: RAW:        4096(      1 blks) ==>   413882116:4108
831: SKP:        4096(      1 blks) ==>   413886224:12
832: RAW:        4096(      1 blks) ==>   413886236:4108
833: SKP:        8192(      2 blks) ==>   413890344:12
834: RAW:        4096(      1 blks) ==>   413890356:4108
835: SKP:        4096(      1 blks) ==>   413894464:12
836: RAW:        4096(      1 blks) ==>   413894476:4108
837: SKP:        4096(      1 blks) ==>   413898584:12
838: RAW:       12288(      3 blks) ==>   413898596:12300
839: SKP:        8192(      2 blks) ==>   413910896:12
840: RAW:        4096(      1 blks) ==>   413910908:4108
841: SKP:        4096(      1 blks) ==>   413915016:12
842: RAW:        4096(      1 blks) ==>   413915028:4108
843: SKP:        4096(      1 blks) ==>   413919136:12
844: RAW:       16384(      4 blks) ==>   413919148:16396
845: SKP:        4096(      1 blks) ==>   413935544:12
846: RAW:        4096(      1 blks) ==>   413935556:4108
847: SKP:        4096(      1 blks) ==>   413939664:12
848: RAW:        4096(      1 blks) ==>   413939676:4108
849: SKP:        8192(      2 blks) ==>   413943784:12
850: RAW:       12288(      3 blks) ==>   413943796:12300
851: SKP:        4096(      1 blks) ==>   413956096:12
852: RAW:        4096(      1 blks) ==>   413956108:4108
853: SKP:        4096(      1 blks) ==>   413960216:12
854: RAW:        4096(      1 blks) ==>   413960228:4108
855: SKP:        8192(      2 blks) ==>   413964336:12
856: RAW:       12288(      3 blks) ==>   413964348:12300
857: SKP:        4096(      1 blks) ==>   413976648:12
858: RAW:        4096(      1 blks) ==>   413976660:4108
859: SKP:        4096(      1 blks) ==>   413980768:12
860: RAW:        4096(      1 blks) ==>   413980780:4108
861: SKP:        8192(      2 blks) ==>   413984888:12
862: RAW:        4096(      1 blks) ==>   413984900:4108
863: SKP:        4096(      1 blks) ==>   413989008:12
864: RAW:        4096(      1 blks) ==>   413989020:4108
865: SKP:        4096(      1 blks) ==>   413993128:12
866: RAW:       16384(      4 blks) ==>   413993140:16396
867: SKP:        4096(      1 blks) ==>   414009536:12
868: RAW:        4096(      1 blks) ==>   414009548:4108
869: SKP:        4096(      1 blks) ==>   414013656:12
870: RAW:        4096(      1 blks) ==>   414013668:4108
871: SKP:        4096(      1 blks) ==>   414017776:12
872: RAW:       16384(      4 blks) ==>   414017788:16396
873: SKP:        4096(      1 blks) ==>   414034184:12
874: RAW:        4096(      1 blks) ==>   414034196:4108
875: SKP:        4096(      1 blks) ==>   414038304:12
876: RAW:        4096(      1 blks) ==>   414038316:4108
877: SKP:        8192(      2 blks) ==>   414042424:12
878: RAW:       12288(      3 blks) ==>   414042436:12300
879: SKP:        4096(      1 blks) ==>   414054736:12
880: RAW:        4096(      1 blks) ==>   414054748:4108
881: SKP:        4096(      1 blks) ==>   414058856:12
882: RAW:        4096(      1 blks) ==>   414058868:4108
883: SKP:        8192(      2 blks) ==>   414062976:12
884: RAW:        4096(      1 blks) ==>   414062988:4108
885: SKP:        4096(      1 blks) ==>   414067096:12
886: RAW:        4096(      1 blks) ==>   414067108:4108
887: SKP:        4096(      1 blks) ==>   414071216:12
888: RAW:        8192(      2 blks) ==>   414071228:8204
889: SKP:       12288(      3 blks) ==>   414079432:12
890: RAW:        4096(      1 blks) ==>   414079444:4108
891: SKP:       12288(      3 blks) ==>   414083552:12
892: RAW:        8192(      2 blks) ==>   414083564:8204
893: SKP:       12288(      3 blks) ==>   414091768:12
894: RAW:        8192(      2 blks) ==>   414091780:8204
895: SKP:       12288(      3 blks) ==>   414099984:12
896: RAW:        4096(      1 blks) ==>   414099996:4108
897: SKP:       12288(      3 blks) ==>   414104104:12
898: RAW:        8192(      2 blks) ==>   414104116:8204
899: SKP:       12288(      3 blks) ==>   414112320:12
900: RAW:        4096(      1 blks) ==>   414112332:4108
901: SKP:       12288(      3 blks) ==>   414116440:12
902: RAW:        8192(      2 blks) ==>   414116452:8204
903: SKP:       12288(      3 blks) ==>   414124656:12
904: RAW:        4096(      1 blks) ==>   414124668:4108
905: SKP:       12288(      3 blks) ==>   414128776:12
906: RAW:        8192(      2 blks) ==>   414128788:8204
907: SKP:       12288(      3 blks) ==>   414136992:12
908: RAW:        4096(      1 blks) ==>   414137004:4108
909: SKP:       12288(      3 blks) ==>   414141112:12
910: RAW:        8192(      2 blks) ==>   414141124:8204
911: SKP:       12288(      3 blks) ==>   414149328:12
912: RAW:        4096(      1 blks) ==>   414149340:4108
913: SKP:       12288(      3 blks) ==>   414153448:12
914: RAW:        8192(      2 blks) ==>   414153460:8204
915: SKP:       12288(      3 blks) ==>   414161664:12
916: RAW:        8192(      2 blks) ==>   414161676:8204
917: SKP:        8192(      2 blks) ==>   414169880:12
918: RAW:        8192(      2 blks) ==>   414169892:8204
919: SKP:       12288(      3 blks) ==>   414178096:12
920: RAW:        8192(      2 blks) ==>   414178108:8204
921: SKP:       12288(      3 blks) ==>   414186312:12
922: RAW:        4096(      1 blks) ==>   414186324:4108
923: SKP:       12288(      3 blks) ==>   414190432:12
924: RAW:        8192(      2 blks) ==>   414190444:8204
925: SKP:       12288(      3 blks) ==>   414198648:12
926: RAW:        4096(      1 blks) ==>   414198660:4108
927: SKP:       12288(      3 blks) ==>   414202768:12
928: RAW:        4096(      1 blks) ==>   414202780:4108
929: SKP:        4096(      1 blks) ==>   414206888:12
930: RAW:        4096(      1 blks) ==>   414206900:4108
931: SKP:       12288(      3 blks) ==>   414211008:12
932: RAW:        8192(      2 blks) ==>   414211020:8204
933: SKP:       12288(      3 blks) ==>   414219224:12
934: RAW:        4096(      1 blks) ==>   414219236:4108
935: SKP:       12288(      3 blks) ==>   414223344:12
936: RAW:        8192(      2 blks) ==>   414223356:8204
937: SKP:       12288(      3 blks) ==>   414231560:12
938: RAW:       12288(      3 blks) ==>   414231572:12300
939: SKP:       12288(      3 blks) ==>   414243872:12
940: RAW:        4096(      1 blks) ==>   414243884:4108
941: SKP:       12288(      3 blks) ==>   414247992:12
942: RAW:       12288(      3 blks) ==>   414248004:12300
943: SKP:       12288(      3 blks) ==>   414260304:12
944: RAW:        4096(      1 blks) ==>   414260316:4108
945: SKP:       12288(      3 blks) ==>   414264424:12
946: RAW:        8192(      2 blks) ==>   414264436:8204
947: SKP:       12288(      3 blks) ==>   414272640:12
948: RAW:        4096(      1 blks) ==>   414272652:4108
949: SKP:       12288(      3 blks) ==>   414276760:12
950: RAW:        8192(      2 blks) ==>   414276772:8204
951: SKP:       12288(      3 blks) ==>   414284976:12
952: RAW:        4096(      1 blks) ==>   414284988:4108
953: SKP:       12288(      3 blks) ==>   414289096:12
954: RAW:        8192(      2 blks) ==>   414289108:8204
955: SKP:       12288(      3 blks) ==>   414297312:12
956: RAW:        8192(      2 blks) ==>   414297324:8204
957: SKP:       12288(      3 blks) ==>   414305528:12
958: RAW:        4096(      1 blks) ==>   414305540:4108
959: SKP:       12288(      3 blks) ==>   414309648:12
960: RAW:        8192(      2 blks) ==>   414309660:8204
961: SKP:       12288(      3 blks) ==>   414317864:12
962: RAW:        8192(      2 blks) ==>   414317876:8204
963: SKP:       12288(      3 blks) ==>   414326080:12
964: RAW:        4096(      1 blks) ==>   414326092:4108
965: SKP:       12288(      3 blks) ==>   414330200:12
966: RAW:        8192(      2 blks) ==>   414330212:8204
967: SKP:       12288(      3 blks) ==>   414338416:12
968: RAW:        4096(      1 blks) ==>   414338428:4108
969: SKP:       12288(      3 blks) ==>   414342536:12
970: RAW:        8192(      2 blks) ==>   414342548:8204
971: SKP:       12288(      3 blks) ==>   414350752:12
972: RAW:        8192(      2 blks) ==>   414350764:8204
973: SKP:        8192(      2 blks) ==>   414358968:12
974: RAW:        8192(      2 blks) ==>   414358980:8204
975: SKP:       12288(      3 blks) ==>   414367184:12
976: RAW:        8192(      2 blks) ==>   414367196:8204
977: SKP:       12288(      3 blks) ==>   414375400:12
978: RAW:        4096(      1 blks) ==>   414375412:4108
979: SKP:       12288(      3 blks) ==>   414379520:12
980: RAW:        8192(      2 blks) ==>   414379532:8204
981: SKP:       12288(      3 blks) ==>   414387736:12
982: RAW:        8192(      2 blks) ==>   414387748:8204
983: SKP:       12288(      3 blks) ==>   414395952:12
984: RAW:        4096(      1 blks) ==>   414395964:4108
985: SKP:       12288(      3 blks) ==>   414400072:12
986: RAW:        8192(      2 blks) ==>   414400084:8204
987: SKP:       12288(      3 blks) ==>   414408288:12
988: RAW:        8192(      2 blks) ==>   414408300:8204
989: SKP:       12288(      3 blks) ==>   414416504:12
990: RAW:        4096(      1 blks) ==>   414416516:4108
991: SKP:       12288(      3 blks) ==>   414420624:12
992: RAW:        8192(      2 blks) ==>   414420636:8204
993: SKP:       12288(      3 blks) ==>   414428840:12
994: RAW:        4096(      1 blks) ==>   414428852:4108
995: SKP:       12288(      3 blks) ==>   414432960:12
996: RAW:        8192(      2 blks) ==>   414432972:8204
997: SKP:       12288(      3 blks) ==>   414441176:12
998: RAW:        8192(      2 blks) ==>   414441188:8204
999: SKP:       12288(      3 blks) ==>   414449392:12
1000: RAW:        4096(      1 blks) ==>   414449404:4108
1001: SKP:       12288(      3 blks) ==>   414453512:12
1002: RAW:        8192(      2 blks) ==>   414453524:8204
1003: SKP:       12288(      3 blks) ==>   414461728:12
1004: RAW:        8192(      2 blks) ==>   414461740:8204
1005: SKP:       12288(      3 blks) ==>   414469944:12
1006: RAW:        4096(      1 blks) ==>   414469956:4108
1007: SKP:       12288(      3 blks) ==>   414474064:12
1008: RAW:        8192(      2 blks) ==>   414474076:8204
1009: SKP:       12288(      3 blks) ==>   414482280:12
1010: RAW:        8192(      2 blks) ==>   414482292:8204
1011: SKP:        8192(      2 blks) ==>   414490496:12
1012: RAW:        8192(      2 blks) ==>   414490508:8204
1013: SKP:       12288(      3 blks) ==>   414498712:12
1014: RAW:        8192(      2 blks) ==>   414498724:8204
1015: SKP:       12288(      3 blks) ==>   414506928:12
1016: RAW:        8192(      2 blks) ==>   414506940:8204
1017: SKP:       12288(      3 blks) ==>   414515144:12
1018: RAW:        4096(      1 blks) ==>   414515156:4108
1019: SKP:       12288(      3 blks) ==>   414519264:12
1020: RAW:        8192(      2 blks) ==>   414519276:8204
1021: SKP:       12288(      3 blks) ==>   414527480:12
1022: RAW:        4096(      1 blks) ==>   414527492:4108
1023: SKP:       12288(      3 blks) ==>   414531600:12
1024: RAW:        8192(      2 blks) ==>   414531612:8204
1025: SKP:       12288(      3 blks) ==>   414539816:12
1026: RAW:        8192(      2 blks) ==>   414539828:8204
1027: SKP:        8192(      2 blks) ==>   414548032:12
1028: RAW:        8192(      2 blks) ==>   414548044:8204
1029: SKP:       12288(      3 blks) ==>   414556248:12
1030: RAW:       20480(      5 blks) ==>   414556260:20492
1031: SKP:       12288(      3 blks) ==>   414576752:12
1032: RAW:        8192(      2 blks) ==>   414576764:8204
1033: SKP:       12288(      3 blks) ==>   414584968:12
1034: RAW:        4096(      1 blks) ==>   414584980:4108
1035: SKP:       12288(      3 blks) ==>   414589088:12
1036: RAW:        8192(      2 blks) ==>   414589100:8204
1037: SKP:       12288(      3 blks) ==>   414597304:12
1038: RAW:        8192(      2 blks) ==>   414597316:8204
1039: SKP:       12288(      3 blks) ==>   414605520:12
1040: RAW:        4096(      1 blks) ==>   414605532:4108
1041: SKP:       12288(      3 blks) ==>   414609640:12
1042: RAW:        8192(      2 blks) ==>   414609652:8204
1043: SKP:       12288(      3 blks) ==>   414617856:12
1044: RAW:        4096(      1 blks) ==>   414617868:4108
1045: SKP:       12288(      3 blks) ==>   414621976:12
1046: RAW:        8192(      2 blks) ==>   414621988:8204
1047: SKP:       12288(      3 blks) ==>   414630192:12
1048: RAW:       40960(     10 blks) ==>   414630204:40972
1049: SKP:       12288(      3 blks) ==>   414671176:12
1050: RAW:        8192(      2 blks) ==>   414671188:8204
1051: SKP:       12288(      3 blks) ==>   414679392:12
1052: RAW:        4096(      1 blks) ==>   414679404:4108
1053: SKP:       12288(      3 blks) ==>   414683512:12
1054: RAW:        8192(      2 blks) ==>   414683524:8204
1055: SKP:       12288(      3 blks) ==>   414691728:12
1056: RAW:        8192(      2 blks) ==>   414691740:8204
1057: SKP:       12288(      3 blks) ==>   414699944:12
1058: RAW:        8192(      2 blks) ==>   414699956:8204
1059: SKP:       12288(      3 blks) ==>   414708160:12
1060: RAW:        8192(      2 blks) ==>   414708172:8204
1061: SKP:       12288(      3 blks) ==>   414716376:12
1062: RAW:       12288(      3 blks) ==>   414716388:12300
1063: SKP:       12288(      3 blks) ==>   414728688:12
1064: RAW:        4096(      1 blks) ==>   414728700:4108
1065: SKP:       12288(      3 blks) ==>   414732808:12
1066: RAW:        8192(      2 blks) ==>   414732820:8204
1067: SKP:       12288(      3 blks) ==>   414741024:12
1068: RAW:        4096(      1 blks) ==>   414741036:4108
1069: SKP:       12288(      3 blks) ==>   414745144:12
1070: RAW:        8192(      2 blks) ==>   414745156:8204
1071: SKP:       12288(      3 blks) ==>   414753360:12
1072: RAW:        4096(      1 blks) ==>   414753372:4108
1073: SKP:       12288(      3 blks) ==>   414757480:12
1074: RAW:        8192(      2 blks) ==>   414757492:8204
1075: SKP:       12288(      3 blks) ==>   414765696:12
1076: RAW:        8192(      2 blks) ==>   414765708:8204
1077: SKP:       12288(      3 blks) ==>   414773912:12
1078: RAW:        8192(      2 blks) ==>   414773924:8204
1079: SKP:       12288(      3 blks) ==>   414782128:12
1080: RAW:        4096(      1 blks) ==>   414782140:4108
1081: SKP:       12288(      3 blks) ==>   414786248:12
1082: RAW:        8192(      2 blks) ==>   414786260:8204
1083: SKP:       12288(      3 blks) ==>   414794464:12
1084: RAW:        8192(      2 blks) ==>   414794476:8204
1085: SKP:     1568768(    383 blks) ==>   414802680:12
1086: RAW:        4096(      1 blks) ==>   414802692:4108
1087: SKP:       12288(      3 blks) ==>   414806800:12
1088: RAW:        8192(      2 blks) ==>   414806812:8204
1089: SKP:     1568768(    383 blks) ==>   414815016:12
1090: RAW:        4096(      1 blks) ==>   414815028:4108
1091: SKP:       12288(      3 blks) ==>   414819136:12
1092: RAW:       12288(      3 blks) ==>   414819148:12300
1093: SKP:        4096(      1 blks) ==>   414831448:12
1094: RAW:     1036288(    253 blks) ==>   414831460:1036300
1095: SKP:        4096(      1 blks) ==>   415867760:12
1096: RAW:      172032(     42 blks) ==>   415867772:172044
1097: SKP:        8192(      2 blks) ==>   416039816:12
1098: RAW:      184320(     45 blks) ==>   416039828:184332
1099: SKP:        8192(      2 blks) ==>   416224160:12
1100: RAW:      200704(     49 blks) ==>   416224172:200716
1101: SKP:       12288(      3 blks) ==>   416424888:12
1102: RAW:       16384(      4 blks) ==>   416424900:16396
1103: SKP:       32768(      8 blks) ==>   416441296:12
1104: RAW:     7835648(   1913 blks) ==>   416441308:7835660
1105: SKP:       12288(      3 blks) ==>   424276968:12
1106: RAW:       69632(     17 blks) ==>   424276980:69644
1107: SKP:       12288(      3 blks) ==>   424346624:12
1108: RAW:       69632(     17 blks) ==>   424346636:69644
1109: SKP:       12288(      3 blks) ==>   424416280:12
1110: RAW:       65536(     16 blks) ==>   424416292:65548
1111: SKP:       12288(      3 blks) ==>   424481840:12
1112: RAW:       69632(     17 blks) ==>   424481852:69644
1113: SKP:       16384(      4 blks) ==>   424551496:12
1114: RAW:       61440(     15 blks) ==>   424551508:61452
1115: SKP:       12288(      3 blks) ==>   424612960:12
1116: RAW:       61440(     15 blks) ==>   424612972:61452
1117: SKP:       16384(      4 blks) ==>   424674424:12
1118: RAW:     6901760(   1685 blks) ==>   424674436:6901772
1119: SKP:        4096(      1 blks) ==>   431576208:12
1120: RAW:     1540096(    376 blks) ==>   431576220:1540108
1121: SKP:        4096(      1 blks) ==>   433116328:12
1122: RAW:    19079168(   4658 blks) ==>   433116340:19079180
1123: SKP:        8192(      2 blks) ==>   452195520:12
1124: RAW:     2560000(    625 blks) ==>   452195532:2560012
1125: SKP:        8192(      2 blks) ==>   454755544:12
1126: RAW:     2830336(    691 blks) ==>   454755556:2830348
1127: SKP:        4096(      1 blks) ==>   457585904:12
1128: RAW:       16384(      4 blks) ==>   457585916:16396
1129: SKP:        4096(      1 blks) ==>   457602312:12
1130: RAW:      335872(     82 blks) ==>   457602324:335884
1131: SKP:        4096(      1 blks) ==>   457938208:12
1132: RAW:       16384(      4 blks) ==>   457938220:16396
1133: SKP:       61440(     15 blks) ==>   457954616:12
1134: RAW:      126976(     31 blks) ==>   457954628:126988
1135: SKP:        8192(      2 blks) ==>   458081616:12
1136: RAW:       12288(      3 blks) ==>   458081628:12300
1137: SKP:       20480(      5 blks) ==>   458093928:12
1138: RAW:    18919424(   4619 blks) ==>   458093940:18919436
1139: SKP:        8192(      2 blks) ==>   477013376:12
1140: RAW:     2564096(    626 blks) ==>   477013388:2564108
1141: SKP:        8192(      2 blks) ==>   479577496:12
1142: RAW:     2723840(    665 blks) ==>   479577508:2723852
1143: SKP:        4096(      1 blks) ==>   482301360:12
1144: RAW:       16384(      4 blks) ==>   482301372:16396
1145: SKP:        4096(      1 blks) ==>   482317768:12
1146: RAW:      335872(     82 blks) ==>   482317780:335884
1147: SKP:        4096(      1 blks) ==>   482653664:12
1148: RAW:       16384(      4 blks) ==>   482653676:16396
1149: SKP:       61440(     15 blks) ==>   482670072:12
1150: RAW:      126976(     31 blks) ==>   482670084:126988
1151: SKP:        8192(      2 blks) ==>   482797072:12
1152: RAW:       12288(      3 blks) ==>   482797084:12300
1153: SKP:       20480(      5 blks) ==>   482809384:12
1154: RAW:     8802304(   2149 blks) ==>   482809396:8802316
1155: SKP:     4186112(   1022 blks) ==>   491611712:12
1156: RAW:     1581056(    386 blks) ==>   491611724:1581068
1157: SKP:       24576(      6 blks) ==>   493192792:12
1158: RAW:     2244608(    548 blks) ==>   493192804:2244620
1159: SKP:       16384(      4 blks) ==>   495437424:12
1160: RAW:       20480(      5 blks) ==>   495437436:20492
1161: SKP:        4096(      1 blks) ==>   495457928:12
1162: RAW:      184320(     45 blks) ==>   495457940:184332
1163: SKP:      114688(     28 blks) ==>   495642272:12
1164: RAW:    61648896(  15051 blks) ==>   495642284:61648908
1165: SKP:     5459968(   1333 blks) ==>   557291192:12
1166: RAW:    31952896(   7801 blks) ==>   557291204:31952908
1167: SKP:       12288(      3 blks) ==>   589244112:12
1168: RAW:       49152(     12 blks) ==>   589244124:49164
1169: SKP:       36864(      9 blks) ==>   589293288:12
1170: RAW:     9138176(   2231 blks) ==>   589293300:9138188
1171: SKP:       16384(      4 blks) ==>   598431488:12
1172: RAW:    20267008(   4948 blks) ==>   598431500:20267020
1173: SKP:       20480(      5 blks) ==>   618698520:12
1174: RAW:     1957888(    478 blks) ==>   618698532:1957900
1175: SKP:       40960(     10 blks) ==>   620656432:12
1176: RAW:      430080(    105 blks) ==>   620656444:430092
1177: SKP:       45056(     11 blks) ==>   621086536:12
1178: RAW:     1253376(    306 blks) ==>   621086548:1253388
1179: SKP:     1888256(    461 blks) ==>   622339936:12
1180: RAW:    25079808(   6123 blks) ==>   622339948:25079820
1181: SKP:        8192(      2 blks) ==>   647419768:12
1182: RAW:    56143872(  13707 blks) ==>   647419780:56143884
1183: SKP:        8192(      2 blks) ==>   703563664:12
1184: RAW:       57344(     14 blks) ==>   703563676:57356
1185: SKP:     2588672(    632 blks) ==>   703621032:12
1186: RAW:    15327232(   3742 blks) ==>   703621044:15327244
1187: SKP:        8192(      2 blks) ==>   718948288:12
1188: RAW:       57344(     14 blks) ==>   718948300:57356
1189: SKP:     1384448(    338 blks) ==>   719005656:12
1190: RAW:    13377536(   3266 blks) ==>   719005668:13377548
1191: SKP:        8192(      2 blks) ==>   732383216:12
1192: RAW:       57344(     14 blks) ==>   732383228:57356
1193: SKP:     3334144(    814 blks) ==>   732440584:12
1194: RAW:     8400896(   2051 blks) ==>   732440596:8400908
1195: SKP:     4186112(   1022 blks) ==>   740841504:12
1196: RAW:     3715072(    907 blks) ==>   740841516:3715084
1197: SKP:        8192(      2 blks) ==>   744556600:12
1198: RAW:       20480(      5 blks) ==>   744556612:20492
1199: SKP:        4096(      1 blks) ==>   744577104:12
1200: RAW:        8192(      2 blks) ==>   744577116:8204
1201: SKP:       12288(      3 blks) ==>   744585320:12
1202: RAW:       12288(      3 blks) ==>   744585332:12300
1203: SKP:        8192(      2 blks) ==>   744597632:12
1204: RAW:        4096(      1 blks) ==>   744597644:4108
1205: SKP:      397312(     97 blks) ==>   744601752:12
1206: RAW:    13959168(   3408 blks) ==>   744601764:13959180
1207: SKP:        4096(      1 blks) ==>   758560944:12
1208: RAW:      733184(    179 blks) ==>   758560956:733196
1209: SKP:     2080768(    508 blks) ==>   759294152:12
1210: RAW:    43556864(  10634 blks) ==>   759294164:43556876
1211: SKP:        4096(      1 blks) ==>   802851040:12
1212: RAW:    20873216(   5096 blks) ==>   802851052:20873228
1213: SKP:       20480(      5 blks) ==>   823724280:12
1214: RAW:      249856(     61 blks) ==>   823724292:249868
1215: SKP:        8192(      2 blks) ==>   823974160:12
1216: RAW:      184320(     45 blks) ==>   823974172:184332
1217: SKP:        4096(      1 blks) ==>   824158504:12
1218: RAW:      172032(     42 blks) ==>   824158516:172044
1219: SKP:     2035712(    497 blks) ==>   824330560:12
1220: RAW:      405504(     99 blks) ==>   824330572:405516
1221: SKP:       16384(      4 blks) ==>   824736088:12
1222: RAW:        8192(      2 blks) ==>   824736100:8204
1223: SKP:       12288(      3 blks) ==>   824744304:12
1224: RAW:    27197440(   6640 blks) ==>   824744316:27197452
1225: SKP:        8192(      2 blks) ==>   851941768:12
1226: RAW:        4096(      1 blks) ==>   851941780:4108
1227: SKP:        8192(      2 blks) ==>   851945888:12
1228: RAW:       16384(      4 blks) ==>   851945900:16396
1229: SKP:        4096(      1 blks) ==>   851962296:12
1230: RAW:      348160(     85 blks) ==>   851962308:348172
1231: SKP:        4096(      1 blks) ==>   852310480:12
1232: RAW:        4096(      1 blks) ==>   852310492:4108
1233: SKP:        4096(      1 blks) ==>   852314600:12
1234: RAW:      409600(    100 blks) ==>   852314612:409612
1235: SKP:        4096(      1 blks) ==>   852724224:12
1236: RAW:      229376(     56 blks) ==>   852724236:229388
1237: SKP:        4096(      1 blks) ==>   852953624:12
1238: RAW:      155648(     38 blks) ==>   852953636:155660
1239: SKP:        8192(      2 blks) ==>   853109296:12
1240: RAW:      180224(     44 blks) ==>   853109308:180236
1241: SKP:        8192(      2 blks) ==>   853289544:12
1242: RAW:       12288(      3 blks) ==>   853289556:12300
1243: SKP:        4096(      1 blks) ==>   853301856:12
1244: RAW:       32768(      8 blks) ==>   853301868:32780
1245: SKP:       12288(      3 blks) ==>   853334648:12
1246: RAW:       36864(      9 blks) ==>   853334660:36876
1247: SKP:        4096(      1 blks) ==>   853371536:12
1248: RAW:      135168(     33 blks) ==>   853371548:135180
1249: SKP:        8192(      2 blks) ==>   853506728:12
1250: RAW:      520192(    127 blks) ==>   853506740:520204
1251: SKP:        4096(      1 blks) ==>   854026944:12
1252: RAW:       28672(      7 blks) ==>   854026956:28684
1253: SKP:        4096(      1 blks) ==>   854055640:12
1254: RAW:       36864(      9 blks) ==>   854055652:36876
1255: SKP:        4096(      1 blks) ==>   854092528:12
1256: RAW:      565248(    138 blks) ==>   854092540:565260
1257: SKP:     3104768(    758 blks) ==>   854657800:12
1258: RAW:      405504(     99 blks) ==>   854657812:405516
1259: SKP:       16384(      4 blks) ==>   855063328:12
1260: RAW:        8192(      2 blks) ==>   855063340:8204
1261: SKP:       12288(      3 blks) ==>   855071544:12
1262: RAW:    27000832(   6592 blks) ==>   855071556:27000844
1263: SKP:        4096(      1 blks) ==>   882072400:12
1264: RAW:      491520(    120 blks) ==>   882072412:491532
1265: SKP:        8192(      2 blks) ==>   882563944:12
1266: RAW:       49152(     12 blks) ==>   882563956:49164
1267: SKP:       12288(      3 blks) ==>   882613120:12
1268: RAW:        4096(      1 blks) ==>   882613132:4108
1269: SKP:       16384(      4 blks) ==>   882617240:12
1270: RAW:        4096(      1 blks) ==>   882617252:4108
1271: SKP:     5521408(   1348 blks) ==>   882621360:12
1272: RAW:    14999552(   3662 blks) ==>   882621372:14999564
1273: SKP:     1777664(    434 blks) ==>   897620936:12
1274: RAW:    14999552(   3662 blks) ==>   897620948:14999564
1275: SKP:    77275136(  18866 blks) ==>   912620512:12
1276: RAW:       12288(      3 blks) ==>   912620524:12300
1277: SKP:   939511808( 229373 blks) ==>   912632824:12
1278: RAW:       12288(      3 blks) ==>   912632836:12300
1279: SKP:       53248(     13 blks) ==>   912645136:12
1280: RAW:       12288(      3 blks) ==>   912645148:12300
1281: SKP:       53248(     13 blks) ==>   912657448:12
1282: RAW:     5476352(   1337 blks) ==>   912657460:5476364
1283: SKP:    28078080(   6855 blks) ==>   918133824:12
1284: RAW:     4730880(   1155 blks) ==>   918133836:4730892
1285: SKP:    95801344(  23389 blks) ==>   922864728:12
1286: RAW:    47075328(  11493 blks) ==>   922864740:47075340
1287: SKP:        4096(      1 blks) ==>   969940080:12
1288: RAW:    16928768(   4133 blks) ==>   969940092:16928780
1289: SKP:        4096(      1 blks) ==>   986868872:12
1290: RAW:    19730432(   4817 blks) ==>   986868884:19730444
1291: SKP:       12288(      3 blks) ==>  1006599328:12
1292: RAW:      720896(    176 blks) ==>  1006599340:720908
1293: SKP:       12288(      3 blks) ==>  1007320248:12
1294: RAW:     5189632(   1267 blks) ==>  1007320260:5189644
1295: SKP:       20480(      5 blks) ==>  1012509904:12
1296: RAW:    73519104(  17949 blks) ==>  1012509916:73519116
1297: SKP:        8192(      2 blks) ==>  1086029032:12
1298: RAW:     4546560(   1110 blks) ==>  1086029044:4546572
1299: SKP:    33554432(   8192 blks) ==>  1090575616:12
1300: RAW:     6770688(   1653 blks) ==>  1090575628:6770700
1301: SKP:        4096(      1 blks) ==>  1097346328:12
1302: RAW:      114688(     28 blks) ==>  1097346340:114700
1303: SKP:        8192(      2 blks) ==>  1097461040:12
1304: RAW:      401408(     98 blks) ==>  1097461052:401420
1305: SKP:   865116160( 211210 blks) ==>  1097862472:12
1306: RAW:       12288(      3 blks) ==>  1097862484:12300
1307: SKP:   268423168(  65533 blks) ==>  1097874784:12
1308: RAW:       12288(      3 blks) ==>  1097874796:12300
1309: SKP:   671076352( 163837 blks) ==>  1097887096:12
1310: RAW:       20480(      5 blks) ==>  1097887108:20492
1311: SKP:       45056(     11 blks) ==>  1097907600:12
1312: RAW:        8192(      2 blks) ==>  1097907612:8204
1313: SKP:       57344(     14 blks) ==>  1097915816:12
1314: RAW:     3911680(    955 blks) ==>  1097915828:3911692
1315: SKP:    29642752(   7237 blks) ==>  1101827520:12
1316: RAW:     5029888(   1228 blks) ==>  1101827532:5029900
1317: SKP:    95502336(  23316 blks) ==>  1106857432:12
1318: RAW:      335872(     82 blks) ==>  1106857444:335884
1319: SKP:        4096(      1 blks) ==>  1107193328:12
1320: RAW:     2785280(    680 blks) ==>  1107193340:2785292
1321: SKP:       28672(      7 blks) ==>  1109978632:12
1322: RAW:     1048576(    256 blks) ==>  1109978644:1048588
1323: SKP:       20480(      5 blks) ==>  1111027232:12
1324: RAW:      507904(    124 blks) ==>  1111027244:507916
1325: SKP:       28672(      7 blks) ==>  1111535160:12
1326: RAW:     1159168(    283 blks) ==>  1111535172:1159180
1327: SKP:       20480(      5 blks) ==>  1112694352:12
1328: RAW:      798720(    195 blks) ==>  1112694364:798732
1329: SKP:        8192(      2 blks) ==>  1113493096:12
1330: RAW:     2437120(    595 blks) ==>  1113493108:2437132
1331: SKP:        4096(      1 blks) ==>  1115930240:12
1332: RAW:        8192(      2 blks) ==>  1115930252:8204
1333: SKP:      516096(    126 blks) ==>  1115938456:12
1334: RAW:      798720(    195 blks) ==>  1115938468:798732
1335: SKP:        4096(      1 blks) ==>  1116737200:12
1336: RAW:     1118208(    273 blks) ==>  1116737212:1118220
1337: SKP:       32768(      8 blks) ==>  1117855432:12
1338: RAW:      294912(     72 blks) ==>  1117855444:294924
1339: SKP:       20480(      5 blks) ==>  1118150368:12
1340: RAW:      188416(     46 blks) ==>  1118150380:188428
1341: SKP:       16384(      4 blks) ==>  1118338808:12
1342: RAW:     1118208(    273 blks) ==>  1118338820:1118220
1343: SKP:       24576(      6 blks) ==>  1119457040:12
1344: RAW:      876544(    214 blks) ==>  1119457052:876556
1345: SKP:        8192(      2 blks) ==>  1120333608:12
1346: RAW:    10498048(   2563 blks) ==>  1120333620:10498060
1347: SKP:        4096(      1 blks) ==>  1130831680:12
1348: RAW:    29044736(   7091 blks) ==>  1130831692:29044748
1349: SKP:        4096(      1 blks) ==>  1159876440:12
1350: RAW:    43958272(  10732 blks) ==>  1159876452:43958284
1351: SKP:        8192(      2 blks) ==>  1203834736:12
1352: RAW:      290816(     71 blks) ==>  1203834748:290828
1353: SKP:        4096(      1 blks) ==>  1204125576:12
1354: RAW:    12177408(   2973 blks) ==>  1204125588:12177420
1355: SKP:        4096(      1 blks) ==>  1216303008:12
1356: RAW:    32256000(   7875 blks) ==>  1216303020:32256012
1357: SKP:       32768(      8 blks) ==>  1248559032:12
1358: RAW:     5554176(   1356 blks) ==>  1248559044:5554188
1359: SKP:       40960(     10 blks) ==>  1254113232:12
1360: RAW:     8347648(   2038 blks) ==>  1254113244:8347660
1361: SKP:        4096(      1 blks) ==>  1262460904:12
1362: RAW:    12738560(   3110 blks) ==>  1262460916:12738572
1363: SKP:        8192(      2 blks) ==>  1275199488:12
1364: RAW:     4874240(   1190 blks) ==>  1275199500:4874252
1365: SKP:        4096(      1 blks) ==>  1280073752:12
1366: RAW:        8192(      2 blks) ==>  1280073764:8204
1367: SKP:       12288(      3 blks) ==>  1280081968:12
1368: RAW:       12288(      3 blks) ==>  1280081980:12300
1369: SKP:       36864(      9 blks) ==>  1280094280:12
1370: RAW:      933888(    228 blks) ==>  1280094292:933900
1371: SKP:       28672(      7 blks) ==>  1281028192:12
1372: RAW:      577536(    141 blks) ==>  1281028204:577548
1373: SKP:        8192(      2 blks) ==>  1281605752:12
1374: RAW:      499712(    122 blks) ==>  1281605764:499724
1375: SKP:        8192(      2 blks) ==>  1282105488:12
1376: RAW:      954368(    233 blks) ==>  1282105500:954380
1377: SKP:       12288(      3 blks) ==>  1283059880:12
1378: RAW:     4497408(   1098 blks) ==>  1283059892:4497420
1379: SKP:        8192(      2 blks) ==>  1287557312:12
1380: RAW:    26505216(   6471 blks) ==>  1287557324:26505228
1381: SKP:       32768(      8 blks) ==>  1314062552:12
1382: RAW:    10350592(   2527 blks) ==>  1314062564:10350604
1383: SKP:        4096(      1 blks) ==>  1324413168:12
1384: RAW:      798720(    195 blks) ==>  1324413180:798732
1385: SKP:      294912(     72 blks) ==>  1325211912:12
1386: RAW:     4055040(    990 blks) ==>  1325211924:4055052
1387: SKP:        4096(      1 blks) ==>  1329266976:12
1388: RAW:     8974336(   2191 blks) ==>  1329266988:8974348
1389: SKP:       20480(      5 blks) ==>  1338241336:12
1390: RAW:      864256(    211 blks) ==>  1338241348:864268
1391: SKP:       28672(      7 blks) ==>  1339105616:12
1392: RAW:     2269184(    554 blks) ==>  1339105628:2269196
1393: SKP:        8192(      2 blks) ==>  1341374824:12
1394: RAW:     1081344(    264 blks) ==>  1341374836:1081356
1395: SKP:        4096(      1 blks) ==>  1342456192:12
1396: RAW:     1093632(    267 blks) ==>  1342456204:1093644
1397: SKP:        4096(      1 blks) ==>  1343549848:12
1398: RAW:     6823936(   1666 blks) ==>  1343549860:6823948
1399: SKP:        4096(      1 blks) ==>  1350373808:12
1400: RAW:    36134912(   8822 blks) ==>  1350373820:36134924
1401: SKP:        4096(      1 blks) ==>  1386508744:12
1402: RAW:     5971968(   1458 blks) ==>  1386508756:5971980
1403: SKP:        8192(      2 blks) ==>  1392480736:12
1404: RAW:    33013760(   8060 blks) ==>  1392480748:33013772
1405: SKP:       32768(      8 blks) ==>  1425494520:12
1406: RAW:     8060928(   1968 blks) ==>  1425494532:8060940
1407: SKP:        4096(      1 blks) ==>  1433555472:12
1408: RAW:     5103616(   1246 blks) ==>  1433555484:5103628
1409: SKP:      548864(    134 blks) ==>  1438659112:12
1410: RAW:    28774400(   7025 blks) ==>  1438659124:28774412
1411: SKP:       40960(     10 blks) ==>  1467433536:12
1412: RAW:     5193728(   1268 blks) ==>  1467433548:5193740
1413: SKP:        4096(      1 blks) ==>  1472627288:12
1414: RAW:       16384(      4 blks) ==>  1472627300:16396
1415: SKP:        4096(      1 blks) ==>  1472643696:12
1416: RAW:     7778304(   1899 blks) ==>  1472643708:7778316
1417: SKP:        8192(      2 blks) ==>  1480422024:12
1418: RAW:    22921216(   5596 blks) ==>  1480422036:22921228
1419: SKP:        4096(      1 blks) ==>  1503343264:12
1420: RAW:     2809856(    686 blks) ==>  1503343276:2809868
1421: SKP:        4096(      1 blks) ==>  1506153144:12
1422: RAW:    10383360(   2535 blks) ==>  1506153156:10383372
1423: SKP:       40960(     10 blks) ==>  1516536528:12
1424: RAW:     3784704(    924 blks) ==>  1516536540:3784716
1425: SKP:        4096(      1 blks) ==>  1520321256:12
1426: RAW:     1884160(    460 blks) ==>  1520321268:1884172
1427: SKP:        4096(      1 blks) ==>  1522205440:12
1428: RAW:        8192(      2 blks) ==>  1522205452:8204
1429: SKP:       24576(      6 blks) ==>  1522213656:12
1430: RAW:     1605632(    392 blks) ==>  1522213668:1605644
1431: SKP:        4096(      1 blks) ==>  1523819312:12
1432: RAW:     7012352(   1712 blks) ==>  1523819324:7012364
1433: SKP:        4096(      1 blks) ==>  1530831688:12
1434: RAW:     2048000(    500 blks) ==>  1530831700:2048012
1435: SKP:      376832(     92 blks) ==>  1532879712:12
1436: RAW:      233472(     57 blks) ==>  1532879724:233484
1437: SKP:       20480(      5 blks) ==>  1533113208:12
1438: RAW:     3092480(    755 blks) ==>  1533113220:3092492
1439: SKP:        4096(      1 blks) ==>  1536205712:12
1440: RAW:     1277952(    312 blks) ==>  1536205724:1277964
1441: SKP:  1580122112( 385772 blks) ==>  1537483688:12
1442: RAW:        8192(      2 blks) ==>  1537483700:8204
1443: SKP:       57344(     14 blks) ==>  1537491904:12
1444: RAW:        8192(      2 blks) ==>  1537491916:8204
1445: SKP:       57344(     14 blks) ==>  1537500120:12
1446: RAW:     2342912(    572 blks) ==>  1537500132:2342924
1447: SKP:    31211520(   7620 blks) ==>  1539843056:12
1448: RAW:     5341184(   1304 blks) ==>  1539843068:5341196
1449: SKP:    95191040(  23240 blks) ==>  1545184264:12
1450: RAW:       12288(      3 blks) ==>  1545184276:12300
1451: SKP:     4186112(   1022 blks) ==>  1545196576:12
1452: RAW:    48386048(  11813 blks) ==>  1545196588:48386060
1453: SKP:        4096(      1 blks) ==>  1593582648:12
1454: RAW:    12562432(   3067 blks) ==>  1593582660:12562444
1455: SKP:        8192(      2 blks) ==>  1606145104:12
1456: RAW:      139264(     34 blks) ==>  1606145116:139276
1457: SKP:     1810432(    442 blks) ==>  1606284392:12
1458: RAW:    33554432(   8192 blks) ==>  1606284404:33554444
1459: SKP:  1912602624( 466944 blks) ==>  1639838848:12
1460: RAW:       16384(      4 blks) ==>  1639838860:16396
1461: SKP:       49152(     12 blks) ==>  1639855256:12
1462: RAW:        8192(      2 blks) ==>  1639855268:8204
1463: SKP:       57344(     14 blks) ==>  1639863472:12
1464: RAW:     2670592(    652 blks) ==>  1639863484:2670604
1465: SKP:    30883840(   7540 blks) ==>  1642534088:12
1466: RAW:     5902336(   1441 blks) ==>  1642534100:5902348
1467: SKP:    94629888(  23103 blks) ==>  1648436448:12
1468: RAW:        4096(      1 blks) ==>  1648436460:4108
1469: SKP:       61440(     15 blks) ==>  1648440568:12
1470: RAW:      233472(     57 blks) ==>  1648440580:233484
1471: SKP:        8192(      2 blks) ==>  1648674064:12
1472: RAW:      364544(     89 blks) ==>  1648674076:364556
1473: SKP:        4096(      1 blks) ==>  1649038632:12
1474: RAW:        4096(      1 blks) ==>  1649038644:4108
1475: SKP:        4096(      1 blks) ==>  1649042752:12
1476: RAW:      249856(     61 blks) ==>  1649042764:249868
1477: SKP:        8192(      2 blks) ==>  1649292632:12
1478: RAW:        4096(      1 blks) ==>  1649292644:4108
1479: SKP:        4096(      1 blks) ==>  1649296752:12
1480: RAW:      102400(     25 blks) ==>  1649296764:102412
1481: SKP:       20480(      5 blks) ==>  1649399176:12
1482: RAW:       32768(      8 blks) ==>  1649399188:32780
1483: SKP:       20480(      5 blks) ==>  1649431968:12
1484: RAW:     2240512(    547 blks) ==>  1649431980:2240524
1485: SKP:       20480(      5 blks) ==>  1651672504:12
1486: RAW:       24576(      6 blks) ==>  1651672516:24588
1487: SKP:       45056(     11 blks) ==>  1651697104:12
1488: RAW:       57344(     14 blks) ==>  1651697116:57356
1489: SKP:       49152(     12 blks) ==>  1651754472:12
1490: RAW:    12963840(   3165 blks) ==>  1651754484:12963852
1491: SKP:       32768(      8 blks) ==>  1664718336:12
1492: RAW:      864256(    211 blks) ==>  1664718348:864268
1493: SKP:       20480(      5 blks) ==>  1665582616:12
1494: RAW:       20480(      5 blks) ==>  1665582628:20492
1495: SKP:       57344(     14 blks) ==>  1665603120:12
1496: RAW:     2641920(    645 blks) ==>  1665603132:2641932
1497: SKP:       40960(     10 blks) ==>  1668245064:12
1498: RAW:        4096(      1 blks) ==>  1668245076:4108
1499: SKP:       12288(      3 blks) ==>  1668249184:12
1500: RAW:     7168000(   1750 blks) ==>  1668249196:7168012
1501: SKP:       12288(      3 blks) ==>  1675417208:12
1502: RAW:     2531328(    618 blks) ==>  1675417220:2531340
1503: SKP:       12288(      3 blks) ==>  1677948560:12
1504: RAW:     1040384(    254 blks) ==>  1677948572:1040396
1505: SKP:       61440(     15 blks) ==>  1678988968:12
1506: RAW:     2289664(    559 blks) ==>  1678988980:2289676
1507: SKP:       20480(      5 blks) ==>  1681278656:12
1508: RAW:     2990080(    730 blks) ==>  1681278668:2990092
1509: SKP:       32768(      8 blks) ==>  1684268760:12
1510: RAW:      122880(     30 blks) ==>  1684268772:122892
1511: SKP:       12288(      3 blks) ==>  1684391664:12
1512: RAW:       20480(      5 blks) ==>  1684391676:20492
1513: SKP:       49152(     12 blks) ==>  1684412168:12
1514: RAW:      344064(     84 blks) ==>  1684412180:344076
1515: SKP:       49152(     12 blks) ==>  1684756256:12
1516: RAW:      229376(     56 blks) ==>  1684756268:229388
1517: SKP:       28672(      7 blks) ==>  1684985656:12
1518: RAW:      102400(     25 blks) ==>  1684985668:102412
1519: SKP:       49152(     12 blks) ==>  1685088080:12
1520: RAW:       36864(      9 blks) ==>  1685088092:36876
1521: SKP:       32768(      8 blks) ==>  1685124968:12
1522: RAW:      139264(     34 blks) ==>  1685124980:139276
1523: SKP:        8192(      2 blks) ==>  1685264256:12
1524: RAW:       53248(     13 blks) ==>  1685264268:53260
1525: SKP:       16384(      4 blks) ==>  1685317528:12
1526: RAW:       94208(     23 blks) ==>  1685317540:94220
1527: SKP:       40960(     10 blks) ==>  1685411760:12
1528: RAW:       36864(      9 blks) ==>  1685411772:36876
1529: SKP:       32768(      8 blks) ==>  1685448648:12
1530: RAW:       40960(     10 blks) ==>  1685448660:40972
1531: SKP:       28672(      7 blks) ==>  1685489632:12
1532: RAW:       77824(     19 blks) ==>  1685489644:77836
1533: SKP:       57344(     14 blks) ==>  1685567480:12
1534: RAW:       40960(     10 blks) ==>  1685567492:40972
1535: SKP:       28672(      7 blks) ==>  1685608464:12
1536: RAW:       65536(     16 blks) ==>  1685608476:65548
1537: SKP:        4096(      1 blks) ==>  1685674024:12
1538: RAW:       32768(      8 blks) ==>  1685674036:32780
1539: SKP:       36864(      9 blks) ==>  1685706816:12
1540: RAW:      237568(     58 blks) ==>  1685706828:237580
1541: SKP:       20480(      5 blks) ==>  1685944408:12
1542: RAW:      294912(     72 blks) ==>  1685944420:294924
1543: SKP:       36864(      9 blks) ==>  1686239344:12
1544: RAW:      245760(     60 blks) ==>  1686239356:245772
1545: SKP:       20480(      5 blks) ==>  1686485128:12
1546: RAW:      180224(     44 blks) ==>  1686485140:180236
1547: SKP:       36864(      9 blks) ==>  1686665376:12
1548: RAW:       86016(     21 blks) ==>  1686665388:86028
1549: SKP:       49152(     12 blks) ==>  1686751416:12
1550: RAW:      311296(     76 blks) ==>  1686751428:311308
1551: SKP:       20480(      5 blks) ==>  1687062736:12
1552: RAW:       57344(     14 blks) ==>  1687062748:57356
1553: SKP:       20480(      5 blks) ==>  1687120104:12
1554: RAW:       49152(     12 blks) ==>  1687120116:49164
1555: SKP:       20480(      5 blks) ==>  1687169280:12
1556: RAW:      634880(    155 blks) ==>  1687169292:634892
1557: SKP:       61440(     15 blks) ==>  1687804184:12
1558: RAW:       90112(     22 blks) ==>  1687804196:90124
1559: SKP:       16384(      4 blks) ==>  1687894320:12
1560: RAW:      557056(    136 blks) ==>  1687894332:557068
1561: SKP:       20480(      5 blks) ==>  1688451400:12
1562: RAW:       57344(     14 blks) ==>  1688451412:57356
1563: SKP:       32768(      8 blks) ==>  1688508768:12
1564: RAW:      221184(     54 blks) ==>  1688508780:221196
1565: SKP:        4096(      1 blks) ==>  1688729976:12
1566: RAW:     3932160(    960 blks) ==>  1688729988:3932172
1567: SKP:       28672(      7 blks) ==>  1692662160:12
1568: RAW:    13471744(   3289 blks) ==>  1692662172:13471756
1569: SKP:        4096(      1 blks) ==>  1706133928:12
1570: RAW:     2207744(    539 blks) ==>  1706133940:2207756
1571: SKP:       12288(      3 blks) ==>  1708341696:12
1572: RAW:     7544832(   1842 blks) ==>  1708341708:7544844
1573: SKP:        4096(      1 blks) ==>  1715886552:12
1574: RAW:      831488(    203 blks) ==>  1715886564:831500
1575: SKP:        8192(      2 blks) ==>  1716718064:12
1576: RAW:     2166784(    529 blks) ==>  1716718076:2166796
1577: SKP:       24576(      6 blks) ==>  1718884872:12
1578: RAW:      647168(    158 blks) ==>  1718884884:647180
1579: SKP:       40960(     10 blks) ==>  1719532064:12
1580: RAW:       61440(     15 blks) ==>  1719532076:61452
1581: SKP:       16384(      4 blks) ==>  1719593528:12
1582: RAW:      995328(    243 blks) ==>  1719593540:995340
1583: SKP:       40960(     10 blks) ==>  1720588880:12
1584: RAW:      118784(     29 blks) ==>  1720588892:118796
1585: SKP:       24576(      6 blks) ==>  1720707688:12
1586: RAW:      278528(     68 blks) ==>  1720707700:278540
1587: SKP:       53248(     13 blks) ==>  1720986240:12
1588: RAW:      663552(    162 blks) ==>  1720986252:663564
1589: SKP:       36864(      9 blks) ==>  1721649816:12
1590: RAW:       61440(     15 blks) ==>  1721649828:61452
1591: SKP:       36864(      9 blks) ==>  1721711280:12
1592: RAW:       81920(     20 blks) ==>  1721711292:81932
1593: SKP:       53248(     13 blks) ==>  1721793224:12
1594: RAW:      110592(     27 blks) ==>  1721793236:110604
1595: SKP:       24576(      6 blks) ==>  1721903840:12
1596: RAW:       57344(     14 blks) ==>  1721903852:57356
1597: SKP:       12288(      3 blks) ==>  1721961208:12
1598: RAW:       40960(     10 blks) ==>  1721961220:40972
1599: SKP:       28672(      7 blks) ==>  1722002192:12
1600: RAW:       40960(     10 blks) ==>  1722002204:40972
1601: SKP:       28672(      7 blks) ==>  1722043176:12
1602: RAW:     1253376(    306 blks) ==>  1722043188:1253388
1603: SKP:        4096(      1 blks) ==>  1723296576:12
1604: RAW:       98304(     24 blks) ==>  1723296588:98316
1605: SKP:        4096(      1 blks) ==>  1723394904:12
1606: RAW:      131072(     32 blks) ==>  1723394916:131084
1607: SKP:       49152(     12 blks) ==>  1723526000:12
1608: RAW:      200704(     49 blks) ==>  1723526012:200716
1609: SKP:        8192(      2 blks) ==>  1723726728:12
1610: RAW:    10735616(   2621 blks) ==>  1723726740:10735628
1611: SKP:        8192(      2 blks) ==>  1734462368:12
1612: RAW:     7966720(   1945 blks) ==>  1734462380:7966732
1613: SKP:       20480(      5 blks) ==>  1742429112:12
1614: RAW:    24268800(   5925 blks) ==>  1742429124:24268812
1615: SKP:        4096(      1 blks) ==>  1766697936:12
1616: RAW:     3313664(    809 blks) ==>  1766697948:3313676
1617: SKP:        4096(      1 blks) ==>  1770011624:12
1618: RAW:     3321856(    811 blks) ==>  1770011636:3321868
1619: SKP:        8192(      2 blks) ==>  1773333504:12
1620: RAW:     2633728(    643 blks) ==>  1773333516:2633740
1621: SKP:        8192(      2 blks) ==>  1775967256:12
1622: RAW:      462848(    113 blks) ==>  1775967268:462860
1623: SKP:        4096(      1 blks) ==>  1776430128:12
1624: RAW:     3035136(    741 blks) ==>  1776430140:3035148
1625: SKP:       28672(      7 blks) ==>  1779465288:12
1626: RAW:    14409728(   3518 blks) ==>  1779465300:14409740
1627: SKP:        4096(      1 blks) ==>  1793875040:12
1628: RAW:     1593344(    389 blks) ==>  1793875052:1593356
1629: SKP:        8192(      2 blks) ==>  1795468408:12
1630: RAW:     8056832(   1967 blks) ==>  1795468420:8056844
1631: SKP:       20480(      5 blks) ==>  1803525264:12
1632: RAW:    30306304(   7399 blks) ==>  1803525276:30306316
1633: SKP:        4096(      1 blks) ==>  1833831592:12
1634: RAW:       36864(      9 blks) ==>  1833831604:36876
1635: SKP:        8192(      2 blks) ==>  1833868480:12
1636: RAW:       32768(      8 blks) ==>  1833868492:32780
1637: SKP:        8192(      2 blks) ==>  1833901272:12
1638: RAW:       98304(     24 blks) ==>  1833901284:98316
1639: SKP:        4096(      1 blks) ==>  1833999600:12
1640: RAW:       32768(      8 blks) ==>  1833999612:32780
1641: SKP:        4096(      1 blks) ==>  1834032392:12
1642: RAW:       32768(      8 blks) ==>  1834032404:32780
1643: SKP:        4096(      1 blks) ==>  1834065184:12
1644: RAW:       32768(      8 blks) ==>  1834065196:32780
1645: SKP:        4096(      1 blks) ==>  1834097976:12
1646: RAW:       81920(     20 blks) ==>  1834097988:81932
1647: SKP:        4096(      1 blks) ==>  1834179920:12
1648: RAW:       57344(     14 blks) ==>  1834179932:57356
1649: SKP:        4096(      1 blks) ==>  1834237288:12
1650: RAW:       32768(      8 blks) ==>  1834237300:32780
1651: SKP:        4096(      1 blks) ==>  1834270080:12
1652: RAW:       32768(      8 blks) ==>  1834270092:32780
1653: SKP:        4096(      1 blks) ==>  1834302872:12
1654: RAW:       32768(      8 blks) ==>  1834302884:32780
1655: SKP:        4096(      1 blks) ==>  1834335664:12
1656: RAW:      118784(     29 blks) ==>  1834335676:118796
1657: SKP:        4096(      1 blks) ==>  1834454472:12
1658: RAW:       57344(     14 blks) ==>  1834454484:57356
1659: SKP:        4096(      1 blks) ==>  1834511840:12
1660: RAW:       65536(     16 blks) ==>  1834511852:65548
1661: SKP:        4096(      1 blks) ==>  1834577400:12
1662: RAW:       32768(      8 blks) ==>  1834577412:32780
1663: SKP:        4096(      1 blks) ==>  1834610192:12
1664: RAW:       40960(     10 blks) ==>  1834610204:40972
1665: SKP:        4096(      1 blks) ==>  1834651176:12
1666: RAW:       32768(      8 blks) ==>  1834651188:32780
1667: SKP:        4096(      1 blks) ==>  1834683968:12
1668: RAW:       77824(     19 blks) ==>  1834683980:77836
1669: SKP:        4096(      1 blks) ==>  1834761816:12
1670: RAW:       32768(      8 blks) ==>  1834761828:32780
1671: SKP:        4096(      1 blks) ==>  1834794608:12
1672: RAW:      372736(     91 blks) ==>  1834794620:372748
1673: SKP:        4096(      1 blks) ==>  1835167368:12
1674: RAW:       32768(      8 blks) ==>  1835167380:32780
1675: SKP:        4096(      1 blks) ==>  1835200160:12
1676: RAW:       40960(     10 blks) ==>  1835200172:40972
1677: SKP:        4096(      1 blks) ==>  1835241144:12
1678: RAW:       69632(     17 blks) ==>  1835241156:69644
1679: SKP:        4096(      1 blks) ==>  1835310800:12
1680: RAW:    15400960(   3760 blks) ==>  1835310812:15400972
1681: SKP:        4096(      1 blks) ==>  1850711784:12
1682: RAW:     2207744(    539 blks) ==>  1850711796:2207756
1683: SKP:       12288(      3 blks) ==>  1852919552:12
1684: RAW:    13189120(   3220 blks) ==>  1852919564:13189132
1685: SKP:        4096(      1 blks) ==>  1866108696:12
1686: RAW:    11759616(   2871 blks) ==>  1866108708:11759628
1687: SKP:        4096(      1 blks) ==>  1877868336:12
1688: RAW:     3305472(    807 blks) ==>  1877868348:3305484
1689: SKP:        4096(      1 blks) ==>  1881173832:12
1690: RAW:     5582848(   1363 blks) ==>  1881173844:5582860
1691: SKP:       12288(      3 blks) ==>  1886756704:12
1692: RAW:     1892352(    462 blks) ==>  1886756716:1892364
1693: SKP:        4096(      1 blks) ==>  1888649080:12
1694: RAW:    22495232(   5492 blks) ==>  1888649092:22495244
1695: SKP:        4096(      1 blks) ==>  1911144336:12
1696: RAW:       24576(      6 blks) ==>  1911144348:24588
1697: SKP:        4096(      1 blks) ==>  1911168936:12
1698: RAW:       53248(     13 blks) ==>  1911168948:53260
1699: SKP:        4096(      1 blks) ==>  1911222208:12
1700: RAW:       86016(     21 blks) ==>  1911222220:86028
1701: SKP:        8192(      2 blks) ==>  1911308248:12
1702: RAW:       40960(     10 blks) ==>  1911308260:40972
1703: SKP:        4096(      1 blks) ==>  1911349232:12
1704: RAW:       86016(     21 blks) ==>  1911349244:86028
1705: SKP:        4096(      1 blks) ==>  1911435272:12
1706: RAW:       73728(     18 blks) ==>  1911435284:73740
1707: SKP:        4096(      1 blks) ==>  1911509024:12
1708: RAW:       40960(     10 blks) ==>  1911509036:40972
1709: SKP:        8192(      2 blks) ==>  1911550008:12
1710: RAW:       69632(     17 blks) ==>  1911550020:69644
1711: SKP:        8192(      2 blks) ==>  1911619664:12
1712: RAW:       40960(     10 blks) ==>  1911619676:40972
1713: SKP:        8192(      2 blks) ==>  1911660648:12
1714: RAW:       40960(     10 blks) ==>  1911660660:40972
1715: SKP:        4096(      1 blks) ==>  1911701632:12
1716: RAW:       40960(     10 blks) ==>  1911701644:40972
1717: SKP:        8192(      2 blks) ==>  1911742616:12
1718: RAW:       40960(     10 blks) ==>  1911742628:40972
1719: SKP:        4096(      1 blks) ==>  1911783600:12
1720: RAW:       40960(     10 blks) ==>  1911783612:40972
1721: SKP:        4096(      1 blks) ==>  1911824584:12
1722: RAW:       77824(     19 blks) ==>  1911824596:77836
1723: SKP:        4096(      1 blks) ==>  1911902432:12
1724: RAW:       40960(     10 blks) ==>  1911902444:40972
1725: SKP:        8192(      2 blks) ==>  1911943416:12
1726: RAW:       40960(     10 blks) ==>  1911943428:40972
1727: SKP:        4096(      1 blks) ==>  1911984400:12
1728: RAW:       40960(     10 blks) ==>  1911984412:40972
1729: SKP:        8192(      2 blks) ==>  1912025384:12
1730: RAW:       81920(     20 blks) ==>  1912025396:81932
1731: SKP:        4096(      1 blks) ==>  1912107328:12
1732: RAW:       40960(     10 blks) ==>  1912107340:40972
1733: SKP:        4096(      1 blks) ==>  1912148312:12
1734: RAW:      102400(     25 blks) ==>  1912148324:102412
1735: SKP:        4096(      1 blks) ==>  1912250736:12
1736: RAW:       40960(     10 blks) ==>  1912250748:40972
1737: SKP:        8192(      2 blks) ==>  1912291720:12
1738: RAW:       40960(     10 blks) ==>  1912291732:40972
1739: SKP:        4096(      1 blks) ==>  1912332704:12
1740: RAW:       90112(     22 blks) ==>  1912332716:90124
1741: SKP:        4096(      1 blks) ==>  1912422840:12
1742: RAW:       20480(      5 blks) ==>  1912422852:20492
1743: SKP:        4096(      1 blks) ==>  1912443344:12
1744: RAW:       57344(     14 blks) ==>  1912443356:57356
1745: SKP:        4096(      1 blks) ==>  1912500712:12
1746: RAW:       45056(     11 blks) ==>  1912500724:45068
1747: SKP:        4096(      1 blks) ==>  1912545792:12
1748: RAW:       77824(     19 blks) ==>  1912545804:77836
1749: SKP:        8192(      2 blks) ==>  1912623640:12
1750: RAW:       40960(     10 blks) ==>  1912623652:40972
1751: SKP:        8192(      2 blks) ==>  1912664624:12
1752: RAW:       77824(     19 blks) ==>  1912664636:77836
1753: SKP:        8192(      2 blks) ==>  1912742472:12
1754: RAW:       57344(     14 blks) ==>  1912742484:57356
1755: SKP:        4096(      1 blks) ==>  1912799840:12
1756: RAW:      114688(     28 blks) ==>  1912799852:114700
1757: SKP:        4096(      1 blks) ==>  1912914552:12
1758: RAW:       20480(      5 blks) ==>  1912914564:20492
1759: SKP:        4096(      1 blks) ==>  1912935056:12
1760: RAW:       12288(      3 blks) ==>  1912935068:12300
1761: SKP:        4096(      1 blks) ==>  1912947368:12
1762: RAW:       36864(      9 blks) ==>  1912947380:36876
1763: SKP:        4096(      1 blks) ==>  1912984256:12
1764: RAW:       77824(     19 blks) ==>  1912984268:77836
1765: SKP:        8192(      2 blks) ==>  1913062104:12
1766: RAW:       40960(     10 blks) ==>  1913062116:40972
1767: SKP:        4096(      1 blks) ==>  1913103088:12
1768: RAW:       32768(      8 blks) ==>  1913103100:32780
1769: SKP:        4096(      1 blks) ==>  1913135880:12
1770: RAW:    29835264(   7284 blks) ==>  1913135892:29835276
1771: SKP:  1716330496( 419026 blks) ==>  1942971168:12
1772: RAW:        8192(      2 blks) ==>  1942971180:8204
1773: SKP:       57344(     14 blks) ==>  1942979384:12
1774: RAW:        8192(      2 blks) ==>  1942979396:8204
1775: SKP:       57344(     14 blks) ==>  1942987600:12
1776: RAW:     3678208(    898 blks) ==>  1942987612:3678220
1777: SKP:    29876224(   7294 blks) ==>  1946665832:12
1778: RAW:     5943296(   1451 blks) ==>  1946665844:5943308
1779: SKP:    94588928(  23093 blks) ==>  1952609152:12
1780: RAW:       12288(      3 blks) ==>  1952609164:12300
1781: SKP:     4186112(   1022 blks) ==>  1952621464:12
1782: RAW:    64442368(  15733 blks) ==>  1952621476:64442380
1783: SKP:        4096(      1 blks) ==>  2017063856:12
1784: RAW:        4096(      1 blks) ==>  2017063868:4108
1785: SKP:       45056(     11 blks) ==>  2017067976:12
1786: RAW:        8192(      2 blks) ==>  2017067988:8204
1787: SKP:        4096(      1 blks) ==>  2017076192:12
1788: RAW:    18690048(   4563 blks) ==>  2017076204:18690060
1789: SKP:    13266944(   3239 blks) ==>  2035766264:12
1790: RAW:    33554432(   8192 blks) ==>  2035766276:33554444
1791: SKP:  1879048192( 458752 blks) ==>  2069320720:12
1792: RAW:       16384(      4 blks) ==>  2069320732:16396
1793: SKP:       49152(     12 blks) ==>  2069337128:12
1794: RAW:       12288(      3 blks) ==>  2069337140:12300
1795: SKP:       53248(     13 blks) ==>  2069349440:12
1796: RAW:     4542464(   1109 blks) ==>  2069349452:4542476
1797: SKP:    29011968(   7083 blks) ==>  2073891928:12
1798: RAW:     6148096(   1501 blks) ==>  2073891940:6148108
1799: SKP:    94384128(  23043 blks) ==>  2080040048:12
1800: RAW:   114991104(  28074 blks) ==>  2080040060:114991116
1801: SKP:        4096(      1 blks) ==>  2195031176:12
1802: RAW:    23633920(   5770 blks) ==>  2195031188:23633932
1803: SKP:        4096(      1 blks) ==>  2218665120:12
1804: RAW:    26329088(   6428 blks) ==>  2218665132:26329100
1805: SKP:       24576(      6 blks) ==>  2244994232:12
1806: RAW:      102400(     25 blks) ==>  2244994244:102412
1807: SKP:       20480(      5 blks) ==>  2245096656:12
1808: RAW:       65536(     16 blks) ==>  2245096668:65548
1809: SKP:        8192(      2 blks) ==>  2245162216:12
1810: RAW:       61440(     15 blks) ==>  2245162228:61452
1811: SKP:       12288(      3 blks) ==>  2245223680:12
1812: RAW:      282624(     69 blks) ==>  2245223692:282636
1813: SKP:        8192(      2 blks) ==>  2245506328:12
1814: RAW:    56864768(  13883 blks) ==>  2245506340:56864780
1815: SKP:        4096(      1 blks) ==>  2302371120:12
1816: RAW:        4096(      1 blks) ==>  2302371132:4108
1817: SKP:        4096(      1 blks) ==>  2302375240:12
1818: RAW:        8192(      2 blks) ==>  2302375252:8204
1819: SKP:        4096(      1 blks) ==>  2302383456:12
1820: RAW:       49152(     12 blks) ==>  2302383468:49164
1821: SKP:        4096(      1 blks) ==>  2302432632:12
1822: RAW:       28672(      7 blks) ==>  2302432644:28684
1823: SKP:        4096(      1 blks) ==>  2302461328:12
1824: RAW:       24576(      6 blks) ==>  2302461340:24588
1825: SKP:        4096(      1 blks) ==>  2302485928:12
1826: RAW:        8192(      2 blks) ==>  2302485940:8204
1827: SKP:        4096(      1 blks) ==>  2302494144:12
1828: RAW:       20480(      5 blks) ==>  2302494156:20492
1829: SKP:        4096(      1 blks) ==>  2302514648:12
1830: RAW:        8192(      2 blks) ==>  2302514660:8204
1831: SKP:        4096(      1 blks) ==>  2302522864:12
1832: RAW:        4096(      1 blks) ==>  2302522876:4108
1833: SKP:        4096(      1 blks) ==>  2302526984:12
1834: RAW:        8192(      2 blks) ==>  2302526996:8204
1835: SKP:        4096(      1 blks) ==>  2302535200:12
1836: RAW:       53248(     13 blks) ==>  2302535212:53260
1837: SKP:        4096(      1 blks) ==>  2302588472:12
1838: RAW:        8192(      2 blks) ==>  2302588484:8204
1839: SKP:        4096(      1 blks) ==>  2302596688:12
1840: RAW:        4096(      1 blks) ==>  2302596700:4108
1841: SKP:        4096(      1 blks) ==>  2302600808:12
1842: RAW:        8192(      2 blks) ==>  2302600820:8204
1843: SKP:        4096(      1 blks) ==>  2302609024:12
1844: RAW:        8192(      2 blks) ==>  2302609036:8204
1845: SKP:        4096(      1 blks) ==>  2302617240:12
1846: RAW:        8192(      2 blks) ==>  2302617252:8204
1847: SKP:        4096(      1 blks) ==>  2302625456:12
1848: RAW:      131072(     32 blks) ==>  2302625468:131084
1849: SKP:        4096(      1 blks) ==>  2302756552:12
1850: RAW:        4096(      1 blks) ==>  2302756564:4108
1851: SKP:        4096(      1 blks) ==>  2302760672:12
1852: RAW:     1417216(    346 blks) ==>  2302760684:1417228
1853: SKP:        4096(      1 blks) ==>  2304177912:12
1854: RAW:      233472(     57 blks) ==>  2304177924:233484
1855: SKP:        4096(      1 blks) ==>  2304411408:12
1856: RAW:        4096(      1 blks) ==>  2304411420:4108
1857: SKP:        4096(      1 blks) ==>  2304415528:12
1858: RAW:       12288(      3 blks) ==>  2304415540:12300
1859: SKP:        4096(      1 blks) ==>  2304427840:12
1860: RAW:       36864(      9 blks) ==>  2304427852:36876
1861: SKP:        4096(      1 blks) ==>  2304464728:12
1862: RAW:        8192(      2 blks) ==>  2304464740:8204
1863: SKP:        4096(      1 blks) ==>  2304472944:12
1864: RAW:       49152(     12 blks) ==>  2304472956:49164
1865: SKP:        4096(      1 blks) ==>  2304522120:12
1866: RAW:       16384(      4 blks) ==>  2304522132:16396
1867: SKP:        4096(      1 blks) ==>  2304538528:12
1868: RAW:        4096(      1 blks) ==>  2304538540:4108
1869: SKP:        4096(      1 blks) ==>  2304542648:12
1870: RAW:       36864(      9 blks) ==>  2304542660:36876
1871: SKP:        4096(      1 blks) ==>  2304579536:12
1872: RAW:        4096(      1 blks) ==>  2304579548:4108
1873: SKP:        4096(      1 blks) ==>  2304583656:12
1874: RAW:        4096(      1 blks) ==>  2304583668:4108
1875: SKP:        4096(      1 blks) ==>  2304587776:12
1876: RAW:       16384(      4 blks) ==>  2304587788:16396
1877: SKP:        4096(      1 blks) ==>  2304604184:12
1878: RAW:       20480(      5 blks) ==>  2304604196:20492
1879: SKP:        4096(      1 blks) ==>  2304624688:12
1880: RAW:       28672(      7 blks) ==>  2304624700:28684
1881: SKP:        4096(      1 blks) ==>  2304653384:12
1882: RAW:       16384(      4 blks) ==>  2304653396:16396
1883: SKP:        4096(      1 blks) ==>  2304669792:12
1884: RAW:       40960(     10 blks) ==>  2304669804:40972
1885: SKP:        4096(      1 blks) ==>  2304710776:12
1886: RAW:       20480(      5 blks) ==>  2304710788:20492
1887: SKP:        4096(      1 blks) ==>  2304731280:12
1888: RAW:       20480(      5 blks) ==>  2304731292:20492
1889: SKP:        4096(      1 blks) ==>  2304751784:12
1890: RAW:       28672(      7 blks) ==>  2304751796:28684
1891: SKP:        4096(      1 blks) ==>  2304780480:12
1892: RAW:        8192(      2 blks) ==>  2304780492:8204
1893: SKP:        4096(      1 blks) ==>  2304788696:12
1894: RAW:       12288(      3 blks) ==>  2304788708:12300
1895: SKP:        4096(      1 blks) ==>  2304801008:12
1896: RAW:        4096(      1 blks) ==>  2304801020:4108
1897: SKP:        4096(      1 blks) ==>  2304805128:12
1898: RAW:        8192(      2 blks) ==>  2304805140:8204
1899: SKP:        4096(      1 blks) ==>  2304813344:12
1900: RAW:       20480(      5 blks) ==>  2304813356:20492
1901: SKP:        4096(      1 blks) ==>  2304833848:12
1902: RAW:        8192(      2 blks) ==>  2304833860:8204
1903: SKP:        4096(      1 blks) ==>  2304842064:12
1904: RAW:       49152(     12 blks) ==>  2304842076:49164
1905: SKP:        4096(      1 blks) ==>  2304891240:12
1906: RAW:        8192(      2 blks) ==>  2304891252:8204
1907: SKP:        4096(      1 blks) ==>  2304899456:12
1908: RAW:        8192(      2 blks) ==>  2304899468:8204
1909: SKP:        4096(      1 blks) ==>  2304907672:12
1910: RAW:        4096(      1 blks) ==>  2304907684:4108
1911: SKP:        4096(      1 blks) ==>  2304911792:12
1912: RAW:       32768(      8 blks) ==>  2304911804:32780
1913: SKP:        4096(      1 blks) ==>  2304944584:12
1914: RAW:       20480(      5 blks) ==>  2304944596:20492
1915: SKP:        4096(      1 blks) ==>  2304965088:12
1916: RAW:        4096(      1 blks) ==>  2304965100:4108
1917: SKP:        4096(      1 blks) ==>  2304969208:12
1918: RAW:        8192(      2 blks) ==>  2304969220:8204
1919: SKP:        4096(      1 blks) ==>  2304977424:12
1920: RAW:       28672(      7 blks) ==>  2304977436:28684
1921: SKP:        4096(      1 blks) ==>  2305006120:12
1922: RAW:        8192(      2 blks) ==>  2305006132:8204
1923: SKP:        4096(      1 blks) ==>  2305014336:12
1924: RAW:       28672(      7 blks) ==>  2305014348:28684
1925: SKP:        4096(      1 blks) ==>  2305043032:12
1926: RAW:        8192(      2 blks) ==>  2305043044:8204
1927: SKP:        4096(      1 blks) ==>  2305051248:12
1928: RAW:       16384(      4 blks) ==>  2305051260:16396
1929: SKP:        4096(      1 blks) ==>  2305067656:12
1930: RAW:       12288(      3 blks) ==>  2305067668:12300
1931: SKP:        4096(      1 blks) ==>  2305079968:12
1932: RAW:        8192(      2 blks) ==>  2305079980:8204
1933: SKP:        4096(      1 blks) ==>  2305088184:12
1934: RAW:        4096(      1 blks) ==>  2305088196:4108
1935: SKP:        4096(      1 blks) ==>  2305092304:12
1936: RAW:       45056(     11 blks) ==>  2305092316:45068
1937: SKP:        4096(      1 blks) ==>  2305137384:12
1938: RAW:        8192(      2 blks) ==>  2305137396:8204
1939: SKP:        4096(      1 blks) ==>  2305145600:12
1940: RAW:        4096(      1 blks) ==>  2305145612:4108
1941: SKP:        4096(      1 blks) ==>  2305149720:12
1942: RAW:        8192(      2 blks) ==>  2305149732:8204
1943: SKP:        4096(      1 blks) ==>  2305157936:12
1944: RAW:       20480(      5 blks) ==>  2305157948:20492
1945: SKP:        4096(      1 blks) ==>  2305178440:12
1946: RAW:       20480(      5 blks) ==>  2305178452:20492
1947: SKP:        4096(      1 blks) ==>  2305198944:12
1948: RAW:        4096(      1 blks) ==>  2305198956:4108
1949: SKP:        4096(      1 blks) ==>  2305203064:12
1950: RAW:        8192(      2 blks) ==>  2305203076:8204
1951: SKP:        4096(      1 blks) ==>  2305211280:12
1952: RAW:       32768(      8 blks) ==>  2305211292:32780
1953: SKP:        4096(      1 blks) ==>  2305244072:12
1954: RAW:        8192(      2 blks) ==>  2305244084:8204
1955: SKP:        4096(      1 blks) ==>  2305252288:12
1956: RAW:       28672(      7 blks) ==>  2305252300:28684
1957: SKP:        4096(      1 blks) ==>  2305280984:12
1958: RAW:       20480(      5 blks) ==>  2305280996:20492
1959: SKP:        4096(      1 blks) ==>  2305301488:12
1960: RAW:       36864(      9 blks) ==>  2305301500:36876
1961: SKP:        4096(      1 blks) ==>  2305338376:12
1962: RAW:       20480(      5 blks) ==>  2305338388:20492
1963: SKP:        4096(      1 blks) ==>  2305358880:12
1964: RAW:       16384(      4 blks) ==>  2305358892:16396
1965: SKP:        4096(      1 blks) ==>  2305375288:12
1966: RAW:        4096(      1 blks) ==>  2305375300:4108
1967: SKP:        4096(      1 blks) ==>  2305379408:12
1968: RAW:       20480(      5 blks) ==>  2305379420:20492
1969: SKP:        4096(      1 blks) ==>  2305399912:12
1970: RAW:      200704(     49 blks) ==>  2305399924:200716
1971: SKP:        4096(      1 blks) ==>  2305600640:12
1972: RAW:        4096(      1 blks) ==>  2305600652:4108
1973: SKP:        4096(      1 blks) ==>  2305604760:12
1974: RAW:        8192(      2 blks) ==>  2305604772:8204
1975: SKP:        4096(      1 blks) ==>  2305612976:12
1976: RAW:        4096(      1 blks) ==>  2305612988:4108
1977: SKP:        4096(      1 blks) ==>  2305617096:12
1978: RAW:        8192(      2 blks) ==>  2305617108:8204
1979: SKP:        4096(      1 blks) ==>  2305625312:12
1980: RAW:       57344(     14 blks) ==>  2305625324:57356
1981: SKP:        4096(      1 blks) ==>  2305682680:12
1982: RAW:        4096(      1 blks) ==>  2305682692:4108
1983: SKP:        4096(      1 blks) ==>  2305686800:12
1984: RAW:        8192(      2 blks) ==>  2305686812:8204
1985: SKP:        4096(      1 blks) ==>  2305695016:12
1986: RAW:        8192(      2 blks) ==>  2305695028:8204
1987: SKP:        4096(      1 blks) ==>  2305703232:12
1988: RAW:        8192(      2 blks) ==>  2305703244:8204
1989: SKP:        4096(      1 blks) ==>  2305711448:12
1990: RAW:    13987840(   3415 blks) ==>  2305711460:13987852
1991: SKP:       16384(      4 blks) ==>  2319699312:12
1992: RAW:       16384(      4 blks) ==>  2319699324:16396
1993: SKP:        4096(      1 blks) ==>  2319715720:12
1994: RAW:    10321920(   2520 blks) ==>  2319715732:10321932
1995: SKP:       28672(      7 blks) ==>  2330037664:12
1996: RAW:        8192(      2 blks) ==>  2330037676:8204
1997: SKP:        4096(      1 blks) ==>  2330045880:12
1998: RAW:       12288(      3 blks) ==>  2330045892:12300
1999: SKP:      765952(    187 blks) ==>  2330058192:12
2000: RAW:    22192128(   5418 blks) ==>  2330058204:22192140
2001: SKP:  1739796480( 424755 blks) ==>  2352250344:12
2002: RAW:       24576(      6 blks) ==>  2352250356:24588
2003: SKP:       40960(     10 blks) ==>  2352274944:12
2004: RAW:       24576(      6 blks) ==>  2352274956:24588
2005: SKP:       40960(     10 blks) ==>  2352299544:12
2006: RAW:    10518528(   2568 blks) ==>  2352299556:10518540
2007: SKP:    23035904(   5624 blks) ==>  2362818096:12
2008: RAW:    40198144(   9814 blks) ==>  2362818108:40198156
2009: SKP:    60334080(  14730 blks) ==>  2403016264:12
2010: RAW:   193372160(  47210 blks) ==>  2403016276:193372172
2011: SKP:        4096(      1 blks) ==>  2596388448:12
2012: RAW:     4710400(   1150 blks) ==>  2596388460:4710412
2013: SKP:        4096(      1 blks) ==>  2601098872:12
2014: RAW:    75292672(  18382 blks) ==>  2601098884:75292684
2015: SKP:        4096(      1 blks) ==>  2676391568:12
2016: RAW:     1724416(    421 blks) ==>  2676391580:1724428
2017: SKP:        4096(      1 blks) ==>  2678116008:12
2018: RAW:        4096(      1 blks) ==>  2678116020:4108
2019: SKP:        4096(      1 blks) ==>  2678120128:12
2020: RAW:     1404928(    343 blks) ==>  2678120140:1404940
2021: SKP:       12288(      3 blks) ==>  2679525080:12
2022: RAW:     2322432(    567 blks) ==>  2679525092:2322444
2023: SKP:       20480(      5 blks) ==>  2681847536:12
2024: RAW:        8192(      2 blks) ==>  2681847548:8204
2025: SKP:        4096(      1 blks) ==>  2681855752:12
2026: RAW:        8192(      2 blks) ==>  2681855764:8204
2027: SKP:        8192(      2 blks) ==>  2681863968:12
2028: RAW:        4096(      1 blks) ==>  2681863980:4108
2029: SKP:        4096(      1 blks) ==>  2681868088:12
2030: RAW:       12288(      3 blks) ==>  2681868100:12300
2031: SKP:        4096(      1 blks) ==>  2681880400:12
2032: RAW:    13254656(   3236 blks) ==>  2681880412:13254668
2033: SKP:        4096(      1 blks) ==>  2695135080:12
2034: RAW:        4096(      1 blks) ==>  2695135092:4108
2035: SKP:        8192(      2 blks) ==>  2695139200:12
2036: RAW:     1208320(    295 blks) ==>  2695139212:1208332
2037: SKP:        4096(      1 blks) ==>  2696347544:12
2038: RAW:     2457600(    600 blks) ==>  2696347556:2457612
2039: SKP:       12288(      3 blks) ==>  2698805168:12
2040: RAW:     1732608(    423 blks) ==>  2698805180:1732620
2041: SKP:        8192(      2 blks) ==>  2700537800:12
2042: RAW:     1818624(    444 blks) ==>  2700537812:1818636
2043: SKP:      258048(     63 blks) ==>  2702356448:12
2044: RAW:    15151104(   3699 blks) ==>  2702356460:15151116
2045: SKP:       16384(      4 blks) ==>  2717507576:12
2046: RAW:     2002944(    489 blks) ==>  2717507588:2002956
2047: SKP:        4096(      1 blks) ==>  2719510544:12
2048: RAW:     2076672(    507 blks) ==>  2719510556:2076684
2049: SKP:        4096(      1 blks) ==>  2721587240:12
2050: RAW:     4657152(   1137 blks) ==>  2721587252:4657164
2051: SKP:        4096(      1 blks) ==>  2726244416:12
2052: RAW:      880640(    215 blks) ==>  2726244428:880652
2053: SKP:       24576(      6 blks) ==>  2727125080:12
2054: RAW:        8192(      2 blks) ==>  2727125092:8204
2055: SKP:       20480(      5 blks) ==>  2727133296:12
2056: RAW:     5664768(   1383 blks) ==>  2727133308:5664780
2057: SKP:       61440(     15 blks) ==>  2732798088:12
2058: RAW:        4096(      1 blks) ==>  2732798100:4108
2059: SKP:        4096(      1 blks) ==>  2732802208:12
2060: RAW:        8192(      2 blks) ==>  2732802220:8204
2061: SKP:       49152(     12 blks) ==>  2732810424:12
2062: RAW:       98304(     24 blks) ==>  2732810436:98316
2063: SKP:        4096(      1 blks) ==>  2732908752:12
2064: RAW:       16384(      4 blks) ==>  2732908764:16396
2065: SKP:        8192(      2 blks) ==>  2732925160:12
2066: RAW:       12288(      3 blks) ==>  2732925172:12300
2067: SKP:        4096(      1 blks) ==>  2732937472:12
2068: RAW:       40960(     10 blks) ==>  2732937484:40972
2069: SKP:        4096(      1 blks) ==>  2732978456:12
2070: RAW:     1777664(    434 blks) ==>  2732978468:1777676
2071: SKP:        4096(      1 blks) ==>  2734756144:12
2072: RAW:     3063808(    748 blks) ==>  2734756156:3063820
2073: SKP:       12288(      3 blks) ==>  2737819976:12
2074: RAW:    14524416(   3546 blks) ==>  2737819988:14524428
2075: SKP:        4096(      1 blks) ==>  2752344416:12
2076: RAW:     4575232(   1117 blks) ==>  2752344428:4575244
2077: SKP:       20480(      5 blks) ==>  2756919672:12
2078: RAW:      110592(     27 blks) ==>  2756919684:110604
2079: SKP:       12288(      3 blks) ==>  2757030288:12
2080: RAW:     1585152(    387 blks) ==>  2757030300:1585164
2081: SKP:        4096(      1 blks) ==>  2758615464:12
2082: RAW:     2273280(    555 blks) ==>  2758615476:2273292
2083: SKP:        4096(      1 blks) ==>  2760888768:12
2084: RAW:     1728512(    422 blks) ==>  2760888780:1728524
2085: SKP:        4096(      1 blks) ==>  2762617304:12
2086: RAW:     5435392(   1327 blks) ==>  2762617316:5435404
2087: SKP:       57344(     14 blks) ==>  2768052720:12
2088: RAW:     2256896(    551 blks) ==>  2768052732:2256908
2089: SKP:       12288(      3 blks) ==>  2770309640:12
2090: RAW:     3641344(    889 blks) ==>  2770309652:3641356
2091: SKP:       12288(      3 blks) ==>  2773951008:12
2092: RAW:     8691712(   2122 blks) ==>  2773951020:8691724
2093: SKP:        4096(      1 blks) ==>  2782642744:12
2094: RAW:     1384448(    338 blks) ==>  2782642756:1384460
2095: SKP:       24576(      6 blks) ==>  2784027216:12
2096: RAW:     1556480(    380 blks) ==>  2784027228:1556492
2097: SKP:        8192(      2 blks) ==>  2785583720:12
2098: RAW:     7188480(   1755 blks) ==>  2785583732:7188492
2099: SKP:       20480(      5 blks) ==>  2792772224:12
2100: RAW:     9256960(   2260 blks) ==>  2792772236:9256972
2101: SKP:       12288(      3 blks) ==>  2802029208:12
2102: RAW:     2740224(    669 blks) ==>  2802029220:2740236
2103: SKP:       32768(      8 blks) ==>  2804769456:12
2104: RAW:     5791744(   1414 blks) ==>  2804769468:5791756
2105: SKP:       61440(     15 blks) ==>  2810561224:12
2106: RAW:     6782976(   1656 blks) ==>  2810561236:6782988
2107: SKP:        4096(      1 blks) ==>  2817344224:12
2108: RAW:     2801664(    684 blks) ==>  2817344236:2801676
2109: SKP:        8192(      2 blks) ==>  2820145912:12
2110: RAW:       36864(      9 blks) ==>  2820145924:36876
2111: SKP:        8192(      2 blks) ==>  2820182800:12
2112: RAW:        8192(      2 blks) ==>  2820182812:8204
2113: SKP:        8192(      2 blks) ==>  2820191016:12
2114: RAW:        8192(      2 blks) ==>  2820191028:8204
2115: SKP:       16384(      4 blks) ==>  2820199232:12
2116: RAW:     6217728(   1518 blks) ==>  2820199244:6217740
2117: SKP:        8192(      2 blks) ==>  2826416984:12
2118: RAW:    15364096(   3751 blks) ==>  2826416996:15364108
2119: SKP:       12288(      3 blks) ==>  2841781104:12
2120: RAW:      442368(    108 blks) ==>  2841781116:442380
2121: SKP:       36864(      9 blks) ==>  2842223496:12
2122: RAW:     1847296(    451 blks) ==>  2842223508:1847308
2123: SKP:        4096(      1 blks) ==>  2844070816:12
2124: RAW:     2170880(    530 blks) ==>  2844070828:2170892
2125: SKP:        4096(      1 blks) ==>  2846241720:12
2126: RAW:      212992(     52 blks) ==>  2846241732:213004
2127: SKP:        8192(      2 blks) ==>  2846454736:12
2128: RAW:     4538368(   1108 blks) ==>  2846454748:4538380
2129: SKP:      192512(     47 blks) ==>  2850993128:12
2130: RAW:     4124672(   1007 blks) ==>  2850993140:4124684
2131: SKP:        8192(      2 blks) ==>  2855117824:12
2132: RAW:       16384(      4 blks) ==>  2855117836:16396
2133: SKP:        4096(      1 blks) ==>  2855134232:12
2134: RAW:     3432448(    838 blks) ==>  2855134244:3432460
2135: SKP:       12288(      3 blks) ==>  2858566704:12
2136: RAW:       12288(      3 blks) ==>  2858566716:12300
2137: SKP:        4096(      1 blks) ==>  2858579016:12
2138: RAW:    11513856(   2811 blks) ==>  2858579028:11513868
2139: SKP:        4096(      1 blks) ==>  2870092896:12
2140: RAW:     5808128(   1418 blks) ==>  2870092908:5808140
2141: SKP:        8192(      2 blks) ==>  2875901048:12
2142: RAW:        8192(      2 blks) ==>  2875901060:8204
2143: SKP:        4096(      1 blks) ==>  2875909264:12
2144: RAW:       36864(      9 blks) ==>  2875909276:36876
2145: SKP:        4096(      1 blks) ==>  2875946152:12
2146: RAW:       12288(      3 blks) ==>  2875946164:12300
2147: SKP:        8192(      2 blks) ==>  2875958464:12
2148: RAW:       65536(     16 blks) ==>  2875958476:65548
2149: SKP:        4096(      1 blks) ==>  2876024024:12
2150: RAW:     1060864(    259 blks) ==>  2876024036:1060876
2151: SKP:       16384(      4 blks) ==>  2877084912:12
2152: RAW:        8192(      2 blks) ==>  2877084924:8204
2153: SKP:        4096(      1 blks) ==>  2877093128:12
2154: RAW:      602112(    147 blks) ==>  2877093140:602124
2155: SKP:        4096(      1 blks) ==>  2877695264:12
2156: RAW:     3940352(    962 blks) ==>  2877695276:3940364
2157: SKP:        8192(      2 blks) ==>  2881635640:12
2158: RAW:       16384(      4 blks) ==>  2881635652:16396
2159: SKP:        4096(      1 blks) ==>  2881652048:12
2160: RAW:        8192(      2 blks) ==>  2881652060:8204
2161: SKP:       32768(      8 blks) ==>  2881660264:12
2162: RAW:     2768896(    676 blks) ==>  2881660276:2768908
2163: SKP:        4096(      1 blks) ==>  2884429184:12
2164: RAW:        4096(      1 blks) ==>  2884429196:4108
2165: SKP:        4096(      1 blks) ==>  2884433304:12
2166: RAW:      929792(    227 blks) ==>  2884433316:929804
2167: SKP:        8192(      2 blks) ==>  2885363120:12
2168: RAW:     1835008(    448 blks) ==>  2885363132:1835020
2169: SKP:        4096(      1 blks) ==>  2887198152:12
2170: RAW:      405504(     99 blks) ==>  2887198164:405516
2171: SKP:        4096(      1 blks) ==>  2887603680:12
2172: RAW:       57344(     14 blks) ==>  2887603692:57356
2173: SKP:        4096(      1 blks) ==>  2887661048:12
2174: RAW:      106496(     26 blks) ==>  2887661060:106508
2175: SKP:        4096(      1 blks) ==>  2887767568:12
2176: RAW:     9568256(   2336 blks) ==>  2887767580:9568268
2177: SKP:       57344(     14 blks) ==>  2897335848:12
2178: RAW:     1138688(    278 blks) ==>  2897335860:1138700
2179: SKP:        8192(      2 blks) ==>  2898474560:12
2180: RAW:      409600(    100 blks) ==>  2898474572:409612
2181: SKP:       24576(      6 blks) ==>  2898884184:12
2182: RAW:    10657792(   2602 blks) ==>  2898884196:10657804
2183: SKP:      258048(     63 blks) ==>  2909542000:12
2184: RAW:     3510272(    857 blks) ==>  2909542012:3510284
2185: SKP:        8192(      2 blks) ==>  2913052296:12
2186: RAW:     3350528(    818 blks) ==>  2913052308:3350540
2187: SKP:        4096(      1 blks) ==>  2916402848:12
2188: RAW:      974848(    238 blks) ==>  2916402860:974860
2189: SKP:       16384(      4 blks) ==>  2917377720:12
2190: RAW:     2269184(    554 blks) ==>  2917377732:2269196
2191: SKP:       53248(     13 blks) ==>  2919646928:12
2192: RAW:     4894720(   1195 blks) ==>  2919646940:4894732
2193: SKP:        8192(      2 blks) ==>  2924541672:12
2194: RAW:        8192(      2 blks) ==>  2924541684:8204
2195: SKP:        4096(      1 blks) ==>  2924549888:12
2196: RAW:     5111808(   1248 blks) ==>  2924549900:5111820
2197: SKP:       16384(      4 blks) ==>  2929661720:12
2198: RAW:     3936256(    961 blks) ==>  2929661732:3936268
2199: SKP:        8192(      2 blks) ==>  2933598000:12
2200: RAW:        8192(      2 blks) ==>  2933598012:8204
2201: SKP:       16384(      4 blks) ==>  2933606216:12
2202: RAW:     2580480(    630 blks) ==>  2933606228:2580492
2203: SKP:       12288(      3 blks) ==>  2936186720:12
2204: RAW:     4272128(   1043 blks) ==>  2936186732:4272140
2205: SKP:       20480(      5 blks) ==>  2940458872:12
2206: RAW:        8192(      2 blks) ==>  2940458884:8204
2207: SKP:        8192(      2 blks) ==>  2940467088:12
2208: RAW:     5988352(   1462 blks) ==>  2940467100:5988364
2209: SKP:        4096(      1 blks) ==>  2946455464:12
2210: RAW:        8192(      2 blks) ==>  2946455476:8204
2211: SKP:        4096(      1 blks) ==>  2946463680:12
2212: RAW:        8192(      2 blks) ==>  2946463692:8204
2213: SKP:       28672(      7 blks) ==>  2946471896:12
2214: RAW:        8192(      2 blks) ==>  2946471908:8204
2215: SKP:        4096(      1 blks) ==>  2946480112:12
2216: RAW:        4096(      1 blks) ==>  2946480124:4108
2217: SKP:        8192(      2 blks) ==>  2946484232:12
2218: RAW:     2650112(    647 blks) ==>  2946484244:2650124
2219: SKP:        8192(      2 blks) ==>  2949134368:12
2220: RAW:        4096(      1 blks) ==>  2949134380:4108
2221: SKP:        8192(      2 blks) ==>  2949138488:12
2222: RAW:        8192(      2 blks) ==>  2949138500:8204
2223: SKP:       20480(      5 blks) ==>  2949146704:12
2224: RAW:     1142784(    279 blks) ==>  2949146716:1142796
2225: SKP:        4096(      1 blks) ==>  2950289512:12
2226: RAW:     4476928(   1093 blks) ==>  2950289524:4476940
2227: SKP:        4096(      1 blks) ==>  2954766464:12
2228: RAW:        4096(      1 blks) ==>  2954766476:4108
2229: SKP:        8192(      2 blks) ==>  2954770584:12
2230: RAW:     9252864(   2259 blks) ==>  2954770596:9252876
2231: SKP:        8192(      2 blks) ==>  2964023472:12
2232: RAW:       98304(     24 blks) ==>  2964023484:98316
2233: SKP:        4096(      1 blks) ==>  2964121800:12
2234: RAW:      761856(    186 blks) ==>  2964121812:761868
2235: SKP:        4096(      1 blks) ==>  2964883680:12
2236: RAW:        4096(      1 blks) ==>  2964883692:4108
2237: SKP:       20480(      5 blks) ==>  2964887800:12
2238: RAW:     3981312(    972 blks) ==>  2964887812:3981324
2239: SKP:       20480(      5 blks) ==>  2968869136:12
2240: RAW:     2138112(    522 blks) ==>  2968869148:2138124
2241: SKP:        4096(      1 blks) ==>  2971007272:12
2242: RAW:     8355840(   2040 blks) ==>  2971007284:8355852
2243: SKP:        8192(      2 blks) ==>  2979363136:12
2244: RAW:     8065024(   1969 blks) ==>  2979363148:8065036
2245: SKP:        4096(      1 blks) ==>  2987428184:12
2246: RAW:     6991872(   1707 blks) ==>  2987428196:6991884
2247: SKP:        4096(      1 blks) ==>  2994420080:12
2248: RAW:     3051520(    745 blks) ==>  2994420092:3051532
2249: SKP:        8192(      2 blks) ==>  2997471624:12
2250: RAW:     4726784(   1154 blks) ==>  2997471636:4726796
2251: SKP:       12288(      3 blks) ==>  3002198432:12
2252: RAW:     2080768(    508 blks) ==>  3002198444:2080780
2253: SKP:       20480(      5 blks) ==>  3004279224:12
2254: RAW:     1458176(    356 blks) ==>  3004279236:1458188
2255: SKP:       12288(      3 blks) ==>  3005737424:12
2256: RAW:       69632(     17 blks) ==>  3005737436:69644
2257: SKP:       61440(     15 blks) ==>  3005807080:12
2258: RAW:      532480(    130 blks) ==>  3005807092:532492
2259: SKP:        4096(      1 blks) ==>  3006339584:12
2260: RAW:      270336(     66 blks) ==>  3006339596:270348
2261: SKP:        8192(      2 blks) ==>  3006609944:12
2262: RAW:     9347072(   2282 blks) ==>  3006609956:9347084
2263: SKP:        8192(      2 blks) ==>  3015957040:12
2264: RAW:     1654784(    404 blks) ==>  3015957052:1654796
2265: SKP:        4096(      1 blks) ==>  3017611848:12
2266: RAW:      765952(    187 blks) ==>  3017611860:765964
2267: SKP:        4096(      1 blks) ==>  3018377824:12
2268: RAW:     3641344(    889 blks) ==>  3018377836:3641356
2269: SKP:        4096(      1 blks) ==>  3022019192:12
2270: RAW:     1658880(    405 blks) ==>  3022019204:1658892
2271: SKP:        8192(      2 blks) ==>  3023678096:12
2272: RAW:     5521408(   1348 blks) ==>  3023678108:5521420
2273: SKP:        4096(      1 blks) ==>  3029199528:12
2274: RAW:      925696(    226 blks) ==>  3029199540:925708
2275: SKP:        4096(      1 blks) ==>  3030125248:12
2276: RAW:      253952(     62 blks) ==>  3030125260:253964
2277: SKP:        8192(      2 blks) ==>  3030379224:12
2278: RAW:     1933312(    472 blks) ==>  3030379236:1933324
2279: SKP:        8192(      2 blks) ==>  3032312560:12
2280: RAW:     5586944(   1364 blks) ==>  3032312572:5586956
2281: SKP:       49152(     12 blks) ==>  3037899528:12
2282: RAW:        4096(      1 blks) ==>  3037899540:4108
2283: SKP:       61440(     15 blks) ==>  3037903648:12
2284: RAW:       98304(     24 blks) ==>  3037903660:98316
2285: SKP:       28672(      7 blks) ==>  3038001976:12
2286: RAW:      692224(    169 blks) ==>  3038001988:692236
2287: SKP:       24576(      6 blks) ==>  3038694224:12
2288: RAW:     1232896(    301 blks) ==>  3038694236:1232908
2289: SKP:      360448(     88 blks) ==>  3039927144:12
2290: RAW:     3784704(    924 blks) ==>  3039927156:3784716
2291: SKP:       49152(     12 blks) ==>  3043711872:12
2292: RAW:      811008(    198 blks) ==>  3043711884:811020
2293: SKP:       40960(     10 blks) ==>  3044522904:12
2294: RAW:     3432448(    838 blks) ==>  3044522916:3432460
2295: SKP:   962813952( 235062 blks) ==>  3047955376:12
2296: RAW:       12288(      3 blks) ==>  3047955388:12300
2297: SKP:   402640896(  98301 blks) ==>  3047967688:12
2298: RAW:       12288(      3 blks) ==>  3047967700:12300
2299: SKP:       53248(     13 blks) ==>  3047980000:12
2300: RAW:       16384(      4 blks) ==>  3047980012:16396
2301: SKP:       49152(     12 blks) ==>  3047996408:12
2302: RAW:     7806976(   1906 blks) ==>  3047996420:7806988
2303: SKP:    25747456(   6286 blks) ==>  3055803408:12
2304: RAW:    42115072(  10282 blks) ==>  3055803420:42115084
2305: SKP:    58417152(  14262 blks) ==>  3097918504:12
2306: RAW:    32079872(   7832 blks) ==>  3097918516:32079884
2307: SKP:      290816(     71 blks) ==>  3129998400:12
2308: RAW:    16420864(   4009 blks) ==>  3129998412:16420876
2309: SKP:        4096(      1 blks) ==>  3146419288:12
2310: RAW:    24154112(   5897 blks) ==>  3146419300:24154124
2311: SKP:        4096(      1 blks) ==>  3170573424:12
2312: RAW:     1540096(    376 blks) ==>  3170573436:1540108
2313: SKP:       57344(     14 blks) ==>  3172113544:12
2314: RAW:     4661248(   1138 blks) ==>  3172113556:4661260
2315: SKP:       28672(      7 blks) ==>  3176774816:12
2316: RAW:        8192(      2 blks) ==>  3176774828:8204
2317: SKP:        4096(      1 blks) ==>  3176783032:12
2318: RAW:       12288(      3 blks) ==>  3176783044:12300
2319: SKP:      765952(    187 blks) ==>  3176795344:12
2320: RAW:     1441792(    352 blks) ==>  3176795356:1441804
2321: SKP:       12288(      3 blks) ==>  3178237160:12
2322: RAW:     1409024(    344 blks) ==>  3178237172:1409036
2323: SKP:       28672(      7 blks) ==>  3179646208:12
2324: RAW:    14413824(   3519 blks) ==>  3179646220:14413836
2325: SKP:        4096(      1 blks) ==>  3194060056:12
2326: RAW:        4096(      1 blks) ==>  3194060068:4108
2327: SKP:        4096(      1 blks) ==>  3194064176:12
2328: RAW:        4096(      1 blks) ==>  3194064188:4108
2329: SKP:        4096(      1 blks) ==>  3194068296:12
2330: RAW:        8192(      2 blks) ==>  3194068308:8204
2331: SKP:        4096(      1 blks) ==>  3194076512:12
2332: RAW:        4096(      1 blks) ==>  3194076524:4108
2333: SKP:        4096(      1 blks) ==>  3194080632:12
2334: RAW:     2203648(    538 blks) ==>  3194080644:2203660
2335: SKP:        4096(      1 blks) ==>  3196284304:12
2336: RAW:       16384(      4 blks) ==>  3196284316:16396
2337: SKP:        4096(      1 blks) ==>  3196300712:12
2338: RAW:       16384(      4 blks) ==>  3196300724:16396
2339: SKP:       12288(      3 blks) ==>  3196317120:12
2340: RAW:        4096(      1 blks) ==>  3196317132:4108
2341: SKP:        4096(      1 blks) ==>  3196321240:12
2342: RAW:       12288(      3 blks) ==>  3196321252:12300
2343: SKP:       24576(      6 blks) ==>  3196333552:12
2344: RAW:     2641920(    645 blks) ==>  3196333564:2641932
2345: SKP:       12288(      3 blks) ==>  3198975496:12
2346: RAW:     4313088(   1053 blks) ==>  3198975508:4313100
2347: SKP:       16384(      4 blks) ==>  3203288608:12
2348: RAW:       57344(     14 blks) ==>  3203288620:57356
2349: SKP:       36864(      9 blks) ==>  3203345976:12
2350: RAW:     4636672(   1132 blks) ==>  3203345988:4636684
2351: SKP:       12288(      3 blks) ==>  3207982672:12
2352: RAW:      524288(    128 blks) ==>  3207982684:524300
2353: SKP:        4096(      1 blks) ==>  3208506984:12
2354: RAW:      167936(     41 blks) ==>  3208506996:167948
2355: SKP:       45056(     11 blks) ==>  3208674944:12
2356: RAW:      106496(     26 blks) ==>  3208674956:106508
2357: SKP:       45056(     11 blks) ==>  3208781464:12
2358: RAW:      151552(     37 blks) ==>  3208781476:151564
2359: SKP:       24576(      6 blks) ==>  3208933040:12
2360: RAW:       40960(     10 blks) ==>  3208933052:40972
2361: SKP:       53248(     13 blks) ==>  3208974024:12
2362: RAW:       94208(     23 blks) ==>  3208974036:94220
2363: SKP:       45056(     11 blks) ==>  3209068256:12
2364: RAW:      245760(     60 blks) ==>  3209068268:245772
2365: SKP:       53248(     13 blks) ==>  3209314040:12
2366: RAW:      659456(    161 blks) ==>  3209314052:659468
2367: SKP:       28672(      7 blks) ==>  3209973520:12
2368: RAW:      229376(     56 blks) ==>  3209973532:229388
2369: SKP:       32768(      8 blks) ==>  3210202920:12
2370: RAW:      204800(     50 blks) ==>  3210202932:204812
2371: SKP:        4096(      1 blks) ==>  3210407744:12
2372: RAW:       61440(     15 blks) ==>  3210407756:61452
2373: SKP:       12288(      3 blks) ==>  3210469208:12
2374: RAW:       57344(     14 blks) ==>  3210469220:57356
2375: SKP:       12288(      3 blks) ==>  3210526576:12
2376: RAW:       32768(      8 blks) ==>  3210526588:32780
2377: SKP:       36864(      9 blks) ==>  3210559368:12
2378: RAW:       94208(     23 blks) ==>  3210559380:94220
2379: SKP:       40960(     10 blks) ==>  3210653600:12
2380: RAW:      114688(     28 blks) ==>  3210653612:114700
2381: SKP:       24576(      6 blks) ==>  3210768312:12
2382: RAW:      356352(     87 blks) ==>  3210768324:356364
2383: SKP:        4096(      1 blks) ==>  3211124688:12
2384: RAW:       49152(     12 blks) ==>  3211124700:49164
2385: SKP:       24576(      6 blks) ==>  3211173864:12
2386: RAW:       86016(     21 blks) ==>  3211173876:86028
2387: SKP:       49152(     12 blks) ==>  3211259904:12
2388: RAW:       28672(      7 blks) ==>  3211259916:28684
2389: SKP:       40960(     10 blks) ==>  3211288600:12
2390: RAW:       32768(      8 blks) ==>  3211288612:32780
2391: SKP:       36864(      9 blks) ==>  3211321392:12
2392: RAW:       28672(      7 blks) ==>  3211321404:28684
2393: SKP:       40960(     10 blks) ==>  3211350088:12
2394: RAW:       32768(      8 blks) ==>  3211350100:32780
2395: SKP:       36864(      9 blks) ==>  3211382880:12
2396: RAW:       45056(     11 blks) ==>  3211382892:45068
2397: SKP:       24576(      6 blks) ==>  3211427960:12
2398: RAW:       65536(     16 blks) ==>  3211427972:65548
2399: SKP:        4096(      1 blks) ==>  3211493520:12
2400: RAW:       69632(     17 blks) ==>  3211493532:69644
2401: SKP:        4096(      1 blks) ==>  3211563176:12
2402: RAW:       28672(      7 blks) ==>  3211563188:28684
2403: SKP:       45056(     11 blks) ==>  3211591872:12
2404: RAW:      204800(     50 blks) ==>  3211591884:204812
2405: SKP:        4096(      1 blks) ==>  3211796696:12
2406: RAW:       40960(     10 blks) ==>  3211796708:40972
2407: SKP:       28672(      7 blks) ==>  3211837680:12
2408: RAW:       53248(     13 blks) ==>  3211837692:53260
2409: SKP:       16384(      4 blks) ==>  3211890952:12
2410: RAW:       49152(     12 blks) ==>  3211890964:49164
2411: SKP:       20480(      5 blks) ==>  3211940128:12
2412: RAW:       65536(     16 blks) ==>  3211940140:65548
2413: SKP:        4096(      1 blks) ==>  3212005688:12
2414: RAW:       49152(     12 blks) ==>  3212005700:49164
2415: SKP:       20480(      5 blks) ==>  3212054864:12
2416: RAW:       77824(     19 blks) ==>  3212054876:77836
2417: SKP:       57344(     14 blks) ==>  3212132712:12
2418: RAW:      159744(     39 blks) ==>  3212132724:159756
2419: SKP:       36864(      9 blks) ==>  3212292480:12
2420: RAW:       24576(      6 blks) ==>  3212292492:24588
2421: SKP:       53248(     13 blks) ==>  3212317080:12
2422: RAW:       40960(     10 blks) ==>  3212317092:40972
2423: SKP:       28672(      7 blks) ==>  3212358064:12
2424: RAW:      274432(     67 blks) ==>  3212358076:274444
2425: SKP:       49152(     12 blks) ==>  3212632520:12
2426: RAW:       28672(      7 blks) ==>  3212632532:28684
2427: SKP:       53248(     13 blks) ==>  3212661216:12
2428: RAW:      151552(     37 blks) ==>  3212661228:151564
2429: SKP:       57344(     14 blks) ==>  3212812792:12
2430: RAW:       49152(     12 blks) ==>  3212812804:49164
2431: SKP:       20480(      5 blks) ==>  3212861968:12
2432: RAW:       98304(     24 blks) ==>  3212861980:98316
2433: SKP:       36864(      9 blks) ==>  3212960296:12
2434: RAW:      737280(    180 blks) ==>  3212960308:737292
2435: SKP:       32768(      8 blks) ==>  3213697600:12
2436: RAW:       16384(      4 blks) ==>  3213697612:16396
2437: SKP:       57344(     14 blks) ==>  3213714008:12
2438: RAW:       16384(      4 blks) ==>  3213714020:16396
2439: SKP:       53248(     13 blks) ==>  3213730416:12
2440: RAW:    15597568(   3808 blks) ==>  3213730428:15597580
2441: SKP:       40960(     10 blks) ==>  3229328008:12
2442: RAW:      573440(    140 blks) ==>  3229328020:573452
2443: SKP:        4096(      1 blks) ==>  3229901472:12
2444: RAW:     8417280(   2055 blks) ==>  3229901484:8417292
2445: SKP:  1870073856( 456561 blks) ==>  3238318776:12
2446: RAW:       12288(      3 blks) ==>  3238318788:12300
2447: SKP:       53248(     13 blks) ==>  3238331088:12
2448: RAW:        4096(      1 blks) ==>  3238331100:4108
2449: SKP:       61440(     15 blks) ==>  3238335208:12
2450: RAW:     1953792(    477 blks) ==>  3238335220:1953804
2451: SKP:    31600640(   7715 blks) ==>  3240289024:12
2452: RAW:     5869568(   1433 blks) ==>  3240289036:5869580
2453: SKP:    94662656(  23111 blks) ==>  3246158616:12
2454: RAW:     7237632(   1767 blks) ==>  3246158628:7237644
2455: SKP:        4096(      1 blks) ==>  3253396272:12
2456: RAW:    28123136(   6866 blks) ==>  3253396284:28123148
2457: SKP:       28672(      7 blks) ==>  3281519432:12
2458: RAW:     1511424(    369 blks) ==>  3281519444:1511436
2459: SKP:        4096(      1 blks) ==>  3283030880:12
2460: RAW:      884736(    216 blks) ==>  3283030892:884748
2461: SKP:       36864(      9 blks) ==>  3283915640:12
2462: RAW:      303104(     74 blks) ==>  3283915652:303116
2463: SKP:       24576(      6 blks) ==>  3284218768:12
2464: RAW:     3121152(    762 blks) ==>  3284218780:3121164
2465: SKP:       24576(      6 blks) ==>  3287339944:12
2466: RAW:      106496(     26 blks) ==>  3287339956:106508
2467: SKP:        4096(      1 blks) ==>  3287446464:12
2468: RAW:      618496(    151 blks) ==>  3287446476:618508
2469: SKP:       45056(     11 blks) ==>  3288064984:12
2470: RAW:      241664(     59 blks) ==>  3288064996:241676
2471: SKP:       49152(     12 blks) ==>  3288306672:12
2472: RAW:      323584(     79 blks) ==>  3288306684:323596
2473: SKP:        4096(      1 blks) ==>  3288630280:12
2474: RAW:      815104(    199 blks) ==>  3288630292:815116
2475: SKP:        4096(      1 blks) ==>  3289445408:12
2476: RAW:      126976(     31 blks) ==>  3289445420:126988
2477: SKP:       36864(      9 blks) ==>  3289572408:12
2478: RAW:       65536(     16 blks) ==>  3289572420:65548
2479: SKP:       16384(      4 blks) ==>  3289637968:12
2480: RAW:      245760(     60 blks) ==>  3289637980:245772
2481: SKP:       16384(      4 blks) ==>  3289883752:12
2482: RAW:       94208(     23 blks) ==>  3289883764:94220
2483: SKP:       45056(     11 blks) ==>  3289977984:12
2484: RAW:     1261568(    308 blks) ==>  3289977996:1261580
2485: SKP:       32768(      8 blks) ==>  3291239576:12
2486: RAW:       49152(     12 blks) ==>  3291239588:49164
2487: SKP:       40960(     10 blks) ==>  3291288752:12
2488: RAW:       24576(      6 blks) ==>  3291288764:24588
2489: SKP:       45056(     11 blks) ==>  3291313352:12
2490: RAW:     1884160(    460 blks) ==>  3291313364:1884172
2491: SKP:       49152(     12 blks) ==>  3293197536:12
2492: RAW:      253952(     62 blks) ==>  3293197548:253964
2493: SKP:       49152(     12 blks) ==>  3293451512:12
2494: RAW:       65536(     16 blks) ==>  3293451524:65548
2495: SKP:        4096(      1 blks) ==>  3293517072:12
2496: RAW:     1249280(    305 blks) ==>  3293517084:1249292
2497: SKP:       53248(     13 blks) ==>  3294766376:12
2498: RAW:      212992(     52 blks) ==>  3294766388:213004
2499: SKP:        4096(      1 blks) ==>  3294979392:12
2500: RAW:      172032(     42 blks) ==>  3294979404:172044
2501: SKP:       20480(      5 blks) ==>  3295151448:12
2502: RAW:      315392(     77 blks) ==>  3295151460:315404
2503: SKP:       24576(      6 blks) ==>  3295466864:12
2504: RAW:      167936(     41 blks) ==>  3295466876:167948
2505: SKP:       28672(      7 blks) ==>  3295634824:12
2506: RAW:       53248(     13 blks) ==>  3295634836:53260
2507: SKP:       24576(      6 blks) ==>  3295688096:12
2508: RAW:     4681728(   1143 blks) ==>  3295688108:4681740
2509: SKP:       16384(      4 blks) ==>  3300369848:12
2510: RAW:     1196032(    292 blks) ==>  3300369860:1196044
2511: SKP:       61440(     15 blks) ==>  3301565904:12
2512: RAW:       73728(     18 blks) ==>  3301565916:73740
2513: SKP:       20480(      5 blks) ==>  3301639656:12
2514: RAW:      139264(     34 blks) ==>  3301639668:139276
2515: SKP:       53248(     13 blks) ==>  3301778944:12
2516: RAW:     2334720(    570 blks) ==>  3301778956:2334732
2517: SKP:       40960(     10 blks) ==>  3304113688:12
2518: RAW:       98304(     24 blks) ==>  3304113700:98316
2519: SKP:       32768(      8 blks) ==>  3304212016:12
2520: RAW:     1568768(    383 blks) ==>  3304212028:1568780
2521: SKP:       36864(      9 blks) ==>  3305780808:12
2522: RAW:      155648(     38 blks) ==>  3305780820:155660
2523: SKP:       16384(      4 blks) ==>  3305936480:12
2524: RAW:      339968(     83 blks) ==>  3305936492:339980
2525: SKP:       28672(      7 blks) ==>  3306276472:12
2526: RAW:       57344(     14 blks) ==>  3306276484:57356
2527: SKP:       45056(     11 blks) ==>  3306333840:12
2528: RAW:       24576(      6 blks) ==>  3306333852:24588
2529: SKP:       45056(     11 blks) ==>  3306358440:12
2530: RAW:       53248(     13 blks) ==>  3306358452:53260
2531: SKP:       16384(      4 blks) ==>  3306411712:12
2532: RAW:     1724416(    421 blks) ==>  3306411724:1724428
2533: SKP:       53248(     13 blks) ==>  3308136152:12
2534: RAW:       77824(     19 blks) ==>  3308136164:77836
2535: SKP:       53248(     13 blks) ==>  3308214000:12
2536: RAW:       32768(      8 blks) ==>  3308214012:32780
2537: SKP:       36864(      9 blks) ==>  3308246792:12
2538: RAW:      118784(     29 blks) ==>  3308246804:118796
2539: SKP:        8192(      2 blks) ==>  3308365600:12
2540: RAW:       32768(      8 blks) ==>  3308365612:32780
2541: SKP:       45056(     11 blks) ==>  3308398392:12
2542: RAW:      155648(     38 blks) ==>  3308398404:155660
2543: SKP:       40960(     10 blks) ==>  3308554064:12
2544: RAW:     2293760(    560 blks) ==>  3308554076:2293772
2545: SKP:       20480(      5 blks) ==>  3310847848:12
2546: RAW:      147456(     36 blks) ==>  3310847860:147468
2547: SKP:       45056(     11 blks) ==>  3310995328:12
2548: RAW:      245760(     60 blks) ==>  3310995340:245772
2549: SKP:       16384(      4 blks) ==>  3311241112:12
2550: RAW:       28672(      7 blks) ==>  3311241124:28684
2551: SKP:       49152(     12 blks) ==>  3311269808:12
2552: RAW:       36864(      9 blks) ==>  3311269820:36876
2553: SKP:       32768(      8 blks) ==>  3311306696:12
2554: RAW:       20480(      5 blks) ==>  3311306708:20492
2555: SKP:       49152(     12 blks) ==>  3311327200:12
2556: RAW:       69632(     17 blks) ==>  3311327212:69644
2557: SKP:       61440(     15 blks) ==>  3311396856:12
2558: RAW:      163840(     40 blks) ==>  3311396868:163852
2559: SKP:       36864(      9 blks) ==>  3311560720:12
2560: RAW:     7622656(   1861 blks) ==>  3311560732:7622668
2561: SKP:       49152(     12 blks) ==>  3319183400:12
2562: RAW:     1064960(    260 blks) ==>  3319183412:1064972
2563: SKP:       49152(     12 blks) ==>  3320248384:12
2564: RAW:     3805184(    929 blks) ==>  3320248396:3805196
2565: SKP:       24576(      6 blks) ==>  3324053592:12
2566: RAW:     1413120(    345 blks) ==>  3324053604:1413132
2567: SKP:       53248(     13 blks) ==>  3325466736:12
2568: RAW:      102400(     25 blks) ==>  3325466748:102412
2569: SKP:       32768(      8 blks) ==>  3325569160:12
2570: RAW:     1921024(    469 blks) ==>  3325569172:1921036
2571: SKP:       40960(     10 blks) ==>  3327490208:12
2572: RAW:       98304(     24 blks) ==>  3327490220:98316
2573: SKP:       28672(      7 blks) ==>  3327588536:12
2574: RAW:      729088(    178 blks) ==>  3327588548:729100
2575: SKP:       45056(     11 blks) ==>  3328317648:12
2576: RAW:       49152(     12 blks) ==>  3328317660:49164
2577: SKP:       45056(     11 blks) ==>  3328366824:12
2578: RAW:      155648(     38 blks) ==>  3328366836:155660
2579: SKP:       40960(     10 blks) ==>  3328522496:12
2580: RAW:       40960(     10 blks) ==>  3328522508:40972
2581: SKP:       32768(      8 blks) ==>  3328563480:12
2582: RAW:      221184(     54 blks) ==>  3328563492:221196
2583: SKP:       36864(      9 blks) ==>  3328784688:12
2584: RAW:      118784(     29 blks) ==>  3328784700:118796
2585: SKP:       24576(      6 blks) ==>  3328903496:12
2586: RAW:      954368(    233 blks) ==>  3328903508:954380
2587: SKP:        4096(      1 blks) ==>  3329857888:12
2588: RAW:      372736(     91 blks) ==>  3329857900:372748
2589: SKP:       45056(     11 blks) ==>  3330230648:12
2590: RAW:       24576(      6 blks) ==>  3330230660:24588
2591: SKP:       53248(     13 blks) ==>  3330255248:12
2592: RAW:      733184(    179 blks) ==>  3330255260:733196
2593: SKP:       40960(     10 blks) ==>  3330988456:12
2594: RAW:      536576(    131 blks) ==>  3330988468:536588
2595: SKP:       57344(     14 blks) ==>  3331525056:12
2596: RAW:     2281472(    557 blks) ==>  3331525068:2281484
2597: SKP:       20480(      5 blks) ==>  3333806552:12
2598: RAW:      118784(     29 blks) ==>  3333806564:118796
2599: SKP:       28672(      7 blks) ==>  3333925360:12
2600: RAW:      438272(    107 blks) ==>  3333925372:438284
2601: SKP:       53248(     13 blks) ==>  3334363656:12
2602: RAW:      126976(     31 blks) ==>  3334363668:126988
2603: SKP:       45056(     11 blks) ==>  3334490656:12
2604: RAW:       20480(      5 blks) ==>  3334490668:20492
2605: SKP:       49152(     12 blks) ==>  3334511160:12
2606: RAW:      790528(    193 blks) ==>  3334511172:790540
2607: SKP:       57344(     14 blks) ==>  3335301712:12
2608: RAW:       45056(     11 blks) ==>  3335301724:45068
2609: SKP:       40960(     10 blks) ==>  3335346792:12
2610: RAW:     1114112(    272 blks) ==>  3335346804:1114124
2611: SKP:       28672(      7 blks) ==>  3336460928:12
2612: RAW:       61440(     15 blks) ==>  3336460940:61452
2613: SKP:       49152(     12 blks) ==>  3336522392:12
2614: RAW:      172032(     42 blks) ==>  3336522404:172044
2615: SKP:       28672(      7 blks) ==>  3336694448:12
2616: RAW:      188416(     46 blks) ==>  3336694460:188428
2617: SKP:        8192(      2 blks) ==>  3336882888:12
2618: RAW:       20480(      5 blks) ==>  3336882900:20492
2619: SKP:       53248(     13 blks) ==>  3336903392:12
2620: RAW:       24576(      6 blks) ==>  3336903404:24588
2621: SKP:       45056(     11 blks) ==>  3336927992:12
2622: RAW:       86016(     21 blks) ==>  3336928004:86028
2623: SKP:       49152(     12 blks) ==>  3337014032:12
2624: RAW:       65536(     16 blks) ==>  3337014044:65548
2625: SKP:        4096(      1 blks) ==>  3337079592:12
2626: RAW:     1622016(    396 blks) ==>  3337079604:1622028
2627: SKP:       57344(     14 blks) ==>  3338701632:12
2628: RAW:       57344(     14 blks) ==>  3338701644:57356
2629: SKP:       49152(     12 blks) ==>  3338759000:12
2630: RAW:      753664(    184 blks) ==>  3338759012:753676
2631: SKP:       49152(     12 blks) ==>  3339512688:12
2632: RAW:     2117632(    517 blks) ==>  3339512700:2117644
2633: SKP:       40960(     10 blks) ==>  3341630344:12
2634: RAW:      102400(     25 blks) ==>  3341630356:102412
2635: SKP:       28672(      7 blks) ==>  3341732768:12
2636: RAW:       20480(      5 blks) ==>  3341732780:20492
2637: SKP:       49152(     12 blks) ==>  3341753272:12
2638: RAW:       16384(      4 blks) ==>  3341753284:16396
2639: SKP:       53248(     13 blks) ==>  3341769680:12
2640: RAW:       57344(     14 blks) ==>  3341769692:57356
2641: SKP:       12288(      3 blks) ==>  3341827048:12
2642: RAW:       20480(      5 blks) ==>  3341827060:20492
2643: SKP:       49152(     12 blks) ==>  3341847552:12
2644: RAW:      102400(     25 blks) ==>  3341847564:102412
2645: SKP:       32768(      8 blks) ==>  3341949976:12
2646: RAW:      217088(     53 blks) ==>  3341949988:217100
2647: SKP:       49152(     12 blks) ==>  3342167088:12
2648: RAW:      507904(    124 blks) ==>  3342167100:507916
2649: SKP:       12288(      3 blks) ==>  3342675016:12
2650: RAW:       90112(     22 blks) ==>  3342675028:90124
2651: SKP:       57344(     14 blks) ==>  3342765152:12
2652: RAW:       53248(     13 blks) ==>  3342765164:53260
2653: SKP:       16384(      4 blks) ==>  3342818424:12
2654: RAW:       77824(     19 blks) ==>  3342818436:77836
2655: SKP:       53248(     13 blks) ==>  3342896272:12
2656: RAW:       53248(     13 blks) ==>  3342896284:53260
2657: SKP:       20480(      5 blks) ==>  3342949544:12
2658: RAW:       16384(      4 blks) ==>  3342949556:16396
2659: SKP:       53248(     13 blks) ==>  3342965952:12
2660: RAW:       94208(     23 blks) ==>  3342965964:94220
2661: SKP:       36864(      9 blks) ==>  3343060184:12
2662: RAW:       53248(     13 blks) ==>  3343060196:53260
2663: SKP:       20480(      5 blks) ==>  3343113456:12
2664: RAW:     6012928(   1468 blks) ==>  3343113468:6012940
2665: SKP:        8192(      2 blks) ==>  3349126408:12
2666: RAW:      180224(     44 blks) ==>  3349126420:180236
2667: SKP:       32768(      8 blks) ==>  3349306656:12
2668: RAW:       32768(      8 blks) ==>  3349306668:32780
2669: SKP:       36864(      9 blks) ==>  3349339448:12
2670: RAW:     1851392(    452 blks) ==>  3349339460:1851404
2671: SKP:       53248(     13 blks) ==>  3351190864:12
2672: RAW:       77824(     19 blks) ==>  3351190876:77836
2673: SKP:       20480(      5 blks) ==>  3351268712:12
2674: RAW:      106496(     26 blks) ==>  3351268724:106508
2675: SKP:        4096(      1 blks) ==>  3351375232:12
2676: RAW:     4448256(   1086 blks) ==>  3351375244:4448268
2677: SKP:        4096(      1 blks) ==>  3355823512:12
2678: RAW:      737280(    180 blks) ==>  3355823524:737292
2679: SKP:       32768(      8 blks) ==>  3356560816:12
2680: RAW:      139264(     34 blks) ==>  3356560828:139276
2681: SKP:       32768(      8 blks) ==>  3356700104:12
2682: RAW:       32768(      8 blks) ==>  3356700116:32780
2683: SKP:       36864(      9 blks) ==>  3356732896:12
2684: RAW:      380928(     93 blks) ==>  3356732908:380940
2685: SKP:        4096(      1 blks) ==>  3357113848:12
2686: RAW:      352256(     86 blks) ==>  3357113860:352268
2687: SKP:       49152(     12 blks) ==>  3357466128:12
2688: RAW:       32768(      8 blks) ==>  3357466140:32780
2689: SKP:       45056(     11 blks) ==>  3357498920:12
2690: RAW:       12288(      3 blks) ==>  3357498932:12300
2691: SKP:       57344(     14 blks) ==>  3357511232:12
2692: RAW:      274432(     67 blks) ==>  3357511244:274444
2693: SKP:       49152(     12 blks) ==>  3357785688:12
2694: RAW:      196608(     48 blks) ==>  3357785700:196620
2695: SKP:        8192(      2 blks) ==>  3357982320:12
2696: RAW:      118784(     29 blks) ==>  3357982332:118796
2697: SKP:       20480(      5 blks) ==>  3358101128:12
2698: RAW:      483328(    118 blks) ==>  3358101140:483340
2699: SKP:       53248(     13 blks) ==>  3358584480:12
2700: RAW:       24576(      6 blks) ==>  3358584492:24588
2701: SKP:       45056(     11 blks) ==>  3358609080:12
2702: RAW:      159744(     39 blks) ==>  3358609092:159756
2703: SKP:       45056(     11 blks) ==>  3358768848:12
2704: RAW:       40960(     10 blks) ==>  3358768860:40972
2705: SKP:       28672(      7 blks) ==>  3358809832:12
2706: RAW:    26288128(   6418 blks) ==>  3358809844:26288140
2707: SKP:  1869971456( 456536 blks) ==>  3385097984:12
2708: RAW:        8192(      2 blks) ==>  3385097996:8204
2709: SKP:       57344(     14 blks) ==>  3385106200:12
2710: RAW:        4096(      1 blks) ==>  3385106212:4108
2711: SKP:       61440(     15 blks) ==>  3385110320:12
2712: RAW:      696320(    170 blks) ==>  3385110332:696332
2713: SKP:    32858112(   8022 blks) ==>  3385806664:12
2714: RAW:     4132864(   1009 blks) ==>  3385806676:4132876
2715: SKP:    96399360(  23535 blks) ==>  3389939552:12
2716: RAW:     8478720(   2070 blks) ==>  3389939564:8478732
2717: SKP:        8192(      2 blks) ==>  3398418296:12
2718: RAW:       94208(     23 blks) ==>  3398418308:94220
2719: SKP:  2004684800( 489425 blks) ==>  3398512528:12
2720: RAW:        8192(      2 blks) ==>  3398512540:8204
2721: SKP:       57344(     14 blks) ==>  3398520744:12
2722: RAW:        8192(      2 blks) ==>  3398520756:8204
2723: SKP:       57344(     14 blks) ==>  3398528960:12
2724: RAW:     2555904(    624 blks) ==>  3398528972:2555916
2725: SKP:    30998528(   7568 blks) ==>  3401084888:12
2726: RAW:     2236416(    546 blks) ==>  3401084900:2236428
2727: SKP:    98295808(  23998 blks) ==>  3403321328:12
2728: RAW:     2142208(    523 blks) ==>  3403321340:2142220
2729: SKP:        4096(      1 blks) ==>  3405463560:12
2730: RAW:       32768(      8 blks) ==>  3405463572:32780
2731: SKP:        4096(      1 blks) ==>  3405496352:12
2732: RAW:       32768(      8 blks) ==>  3405496364:32780
2733: SKP:        4096(      1 blks) ==>  3405529144:12
2734: RAW:        8192(      2 blks) ==>  3405529156:8204
2735: SKP:        4096(      1 blks) ==>  3405537360:12
2736: RAW:       12288(      3 blks) ==>  3405537372:12300
2737: SKP:        4096(      1 blks) ==>  3405549672:12
2738: RAW:       20480(      5 blks) ==>  3405549684:20492
2739: SKP:        4096(      1 blks) ==>  3405570176:12
2740: RAW:       61440(     15 blks) ==>  3405570188:61452
2741: SKP:        4096(      1 blks) ==>  3405631640:12
2742: RAW:       36864(      9 blks) ==>  3405631652:36876
2743: SKP:        4096(      1 blks) ==>  3405668528:12
2744: RAW:        8192(      2 blks) ==>  3405668540:8204
2745: SKP:        4096(      1 blks) ==>  3405676744:12
2746: RAW:        8192(      2 blks) ==>  3405676756:8204
2747: SKP:        4096(      1 blks) ==>  3405684960:12
2748: RAW:       20480(      5 blks) ==>  3405684972:20492
2749: SKP:        4096(      1 blks) ==>  3405705464:12
2750: RAW:        8192(      2 blks) ==>  3405705476:8204
2751: SKP:        4096(      1 blks) ==>  3405713680:12
2752: RAW:        8192(      2 blks) ==>  3405713692:8204
2753: SKP:        4096(      1 blks) ==>  3405721896:12
2754: RAW:       40960(     10 blks) ==>  3405721908:40972
2755: SKP:        4096(      1 blks) ==>  3405762880:12
2756: RAW:       20480(      5 blks) ==>  3405762892:20492
2757: SKP:        4096(      1 blks) ==>  3405783384:12
2758: RAW:       24576(      6 blks) ==>  3405783396:24588
2759: SKP:        4096(      1 blks) ==>  3405807984:12
2760: RAW:        8192(      2 blks) ==>  3405807996:8204
2761: SKP:        4096(      1 blks) ==>  3405816200:12
2762: RAW:     6807552(   1662 blks) ==>  3405816212:6807564
2763: SKP:        4096(      1 blks) ==>  3412623776:12
2764: RAW:     5545984(   1354 blks) ==>  3412623788:5545996
2765: SKP:        4096(      1 blks) ==>  3418169784:12
2766: RAW:       73728(     18 blks) ==>  3418169796:73740
2767: SKP:        4096(      1 blks) ==>  3418243536:12
2768: RAW:      204800(     50 blks) ==>  3418243548:204812
2769: SKP:        4096(      1 blks) ==>  3418448360:12
2770: RAW:       32768(      8 blks) ==>  3418448372:32780
2771: SKP:        4096(      1 blks) ==>  3418481152:12
2772: RAW:      421888(    103 blks) ==>  3418481164:421900
2773: SKP:        4096(      1 blks) ==>  3418903064:12
2774: RAW:      143360(     35 blks) ==>  3418903076:143372
2775: SKP:        4096(      1 blks) ==>  3419046448:12
2776: RAW:     6217728(   1518 blks) ==>  3419046460:6217740
2777: SKP:        4096(      1 blks) ==>  3425264200:12
2778: RAW:    71163904(  17374 blks) ==>  3425264212:71163916
2779: SKP:       12288(      3 blks) ==>  3496428128:12
2780: RAW:      282624(     69 blks) ==>  3496428140:282636
2781: SKP:  1919762432( 468692 blks) ==>  3496710776:12
2782: RAW:        4096(      1 blks) ==>  3496710788:4108
2783: SKP:       61440(     15 blks) ==>  3496714896:12
2784: RAW:        4096(      1 blks) ==>  3496714908:4108
2785: SKP:       61440(     15 blks) ==>  3496719016:12
2786: RAW:        4096(      1 blks) ==>  3496719028:4108
2787: SKP:    33550336(   8191 blks) ==>  3496723136:12
2788: RAW:       28672(      7 blks) ==>  3496723148:28684
2789: SKP:  2113769472( 516057 blks) ==>  3496751832:12
2790: RAW:        8192(      2 blks) ==>  3496751844:8204
2791: SKP:       57344(     14 blks) ==>  3496760048:12
2792: RAW:        4096(      1 blks) ==>  3496760060:4108
2793: SKP:       61440(     15 blks) ==>  3496764168:12
2794: RAW:        4096(      1 blks) ==>  3496764180:4108
2795: SKP:    33550336(   8191 blks) ==>  3496768288:12
2796: RAW:       36864(      9 blks) ==>  3496768300:36876
2797: SKP:   100495360(  24535 blks) ==>  3496805176:12
2798: RAW:       16384(      4 blks) ==>  3496805188:16396
2799: SKP:  2013249536( 491516 blks) ==>  3496821584:12
-- Total: -----------------------------------------------------------
2800 CHUNK 30064771072(7340032 blks) ==>  3496821596(853708 blks)

done.
system.img built successfully. 
Existing tbcfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/cboot.bin) reused.
copying tbcdtbfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/kernel/dtb/tegra186-tx2-cti-ASG001-USB3.dtb)... done.
copying cfgfile(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/t186ref/cfg/flash_l4t_t186.xml) to flash.xml... done.
Existing flasher(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/nvtboot_recovery_cpu.bin) reused.
Existing flashapp(/home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/tegraflash.py) reused.
./tegraflash.py --bl nvtboot_recovery_cpu.bin --sdram_config P3310_A00_8GB_Samsung_8GB_lpddr4_204Mhz_A02_l4t.cfg --odmdata 0x1090000 --applet mb1_recovery_prod.bin --cmd "flash; reboot"  --cfg flash.xml --chip 0x18 --misc_config tegra186-mb1-bct-misc-si-l4t.cfg --pinmux_config tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg --pmic_config tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg --pmc_config tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg --prod_config tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg --scr_config minimal_scr.cfg --scr_cold_boot_config mobile_scr.cfg --br_cmd_config tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg --dev_params emmc.cfg  --bins "mb2_bootloader nvtboot_recovery.bin; mts_preboot preboot_d15_prod_cr.bin; mts_bootpack mce_mts_d15_prod_cr.bin; bpmp_fw bpmp.bin; bpmp_fw_dtb tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2.dtb; tlk tos.img; eks eks.img; bootloader_dtb tegra186-tx2-cti-ASG001-USB3.dtb"  
saving flash command in /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/flashcmd.txt
./tegraflash.py --bl nvtboot_recovery_cpu.bin --sdram_config P3310_A00_8GB_Samsung_8GB_lpddr4_204Mhz_A02_l4t.cfg --odmdata 0x1090000 --applet mb1_recovery_prod.bin --cmd "flash; reboot"  --cfg flash.xml --chip 0x18 --misc_config tegra186-mb1-bct-misc-si-l4t.cfg --pinmux_config tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg --pmic_config tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg --pmc_config tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg --prod_config tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg --scr_config minimal_scr.cfg --scr_cold_boot_config mobile_scr.cfg --br_cmd_config tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg --dev_params emmc.cfg  --bins "mb2_bootloader nvtboot_recovery.bin; mts_preboot preboot_d15_prod_cr.bin; mts_bootpack mce_mts_d15_prod_cr.bin; bpmp_fw bpmp.bin; bpmp_fw_dtb tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2.dtb; tlk tos.img; eks eks.img; bootloader_dtb tegra186-tx2-cti-ASG001-USB3.dtb"  
saving flash parameters in /home/chahatdeep/JetPack-L4T/64_TX2/Linux_for_Tegra_tx2/bootloader/flash_parameters.txt
--bl nvtboot_recovery_cpu.bin --sdram_config P3310_A00_8GB_Samsung_8GB_lpddr4_204Mhz_A02_l4t.cfg --odmdata 0x1090000 --applet mb1_recovery_prod.bin --cmd "flash; reboot"  --cfg flash.xml --chip 0x18 --misc_config tegra186-mb1-bct-misc-si-l4t.cfg --pinmux_config tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg --pmic_config tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg --pmc_config tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg --prod_config tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg --scr_config minimal_scr.cfg --scr_cold_boot_config mobile_scr.cfg --br_cmd_config tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg --dev_params emmc.cfg  --bins "mb2_bootloader nvtboot_recovery.bin; mts_preboot preboot_d15_prod_cr.bin; mts_bootpack mce_mts_d15_prod_cr.bin; bpmp_fw bpmp.bin; bpmp_fw_dtb tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2.dtb; tlk tos.img; eks eks.img; bootloader_dtb tegra186-tx2-cti-ASG001-USB3.dtb"  
*** Flashing target device started. ***
Welcome to Tegra Flash
version 1.0.0
Type ? or help for help and q or quit to exit
Use ! to execute system commands
 
[   0.0150 ] tegrasign_v2 --key None --getmode mode.txt
[   0.0174 ] Assuming zero filled SBK key
[   0.0309 ] 
[   0.0310 ] Generating RCM messages
[   0.0463 ] tegrarcm_v2 --listrcm rcm_list.xml --chip 0x18 --download rcm mb1_recovery_prod.bin 0 0
[   0.0487 ] RCM 0 is saved as rcm_0.rcm
[   0.0553 ] RCM 1 is saved as rcm_1.rcm
[   0.0554 ] List of rcm files are saved in rcm_list.xml
[   0.0554 ] 
[   0.0554 ] Signing RCM messages
[   0.0578 ] tegrasign_v2 --key None --list rcm_list.xml --pubkeyhash pub_key.key
[   0.0600 ] Assuming zero filled SBK key
[   0.0675 ] 
[   0.0675 ] Copying signature to RCM mesages
[   0.0684 ] tegrarcm_v2 --chip 0x18 --updatesig rcm_list_signed.xml
[   0.0695 ] 
[   0.0695 ] Parsing partition layout
[   0.0842 ] tegraparser_v2 --pt flash.xml.tmp
[   0.0861 ] 
[   0.0861 ] Creating list of images to be signed
[   0.1022 ] tegrahost_v2 --chip 0x18 --partitionlayout flash.xml.bin --list images_list.xml zerosbk
[   0.3327 ] 
[   0.3328 ] Generating signatures
[   0.3353 ] tegrasign_v2 --key None --list images_list.xml --pubkeyhash pub_key.key
[   0.3376 ] Assuming zero filled SBK key
[   0.4401 ] 
[   0.4402 ] Generating br-bct
[   0.4420 ] Updating dev and MSS params in BR BCT
[   0.4421 ] tegrabct_v2 --dev_param emmc.cfg --sdram P3310_A00_8GB_Samsung_8GB_lpddr4_204Mhz_A02_l4t.cfg --brbct br_bct.cfg --chip 0x18
[   0.4694 ] 
[   0.4694 ] Updating bl info
[   0.4703 ] tegrabct_v2 --brbct br_bct_BR.bct --chip 0x18 --updateblinfo flash.xml.bin --updatesig images_list_signed.xml
[   0.4716 ] 
[   0.4716 ] Updating smd info
[   0.4724 ] tegrabct_v2 --brbct br_bct_BR.bct --chip 0x18 --updatesmdinfo flash.xml.bin
[   0.4735 ] 
[   0.4736 ] Updating Odmdata
[   0.4744 ] tegrabct_v2 --brbct br_bct_BR.bct --chip 0x18 --updatefields Odmdata =0x1090000
[   0.4756 ] 
[   0.4756 ] Get Signed section bct
[   0.4764 ] tegrabct_v2 --brbct br_bct_BR.bct --chip 0x18 --listbct bct_list.xml
[   0.4773 ] 
[   0.4773 ] Signing BCT
[   0.4787 ] tegrasign_v2 --key None --list bct_list.xml --pubkeyhash pub_key.key
[   0.4795 ] Assuming zero filled SBK key
[   0.4796 ] 
[   0.4796 ] Updating BCT with signature
[   0.4803 ] tegrabct_v2 --brbct br_bct_BR.bct --chip 0x18 --updatesig bct_list_signed.xml
[   0.4815 ] 
[   0.4815 ] Generating coldboot mb1-bct
[   0.4824 ] tegrabct_v2 --chip 0x18 --mb1bct mb1_cold_boot_bct.cfg --sdram P3310_A00_8GB_Samsung_8GB_lpddr4_204Mhz_A02_l4t.cfg --misc tegra186-mb1-bct-misc-si-l4t.cfg --scr mobile_scr.cfg --pinmux tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg --pmc tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg --pmic tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg --brcommand tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg --prod tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg
[   0.4832 ] MB1-BCT version: 0xe
[   0.4833 ] Copying Sdram info from 2 to 3 set
[   0.4941 ] Copying Sdram info from 0 to 1 set
[   0.4944 ] Packing sdram param for instance[0]
[   0.4946 ] Packing sdram param for instance[1]
[   0.4947 ] Packing sdram param for instance[2]
[   0.4948 ] Packing sdram param for instance[3]

[   0.4950 ] Parsing config file :tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg 
[   0.4953 ] Appending platform config data of size :- 2904

[   0.4955 ] Parsing config file :mobile_scr.cfg 
[   0.4956 ] Appending platform config data of size :- 12240

[   0.4969 ] Parsing config file :tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg 
[   0.4972 ] Appending platform config data of size :- 24
[   0.4973 ] 
[   0.4973 ] Parsing config file :tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg 
[   0.4973 ] Appending platform config data of size :- 708
[   0.4974 ] 
[   0.4974 ] Parsing config file :tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg 
[   0.4974 ] Appending platform config data of size :- 64
[   0.4974 ] 
[   0.4974 ] Parsing config file :tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg 
[   0.4974 ] Appending platform config data of size :- 1628
[   0.4974 ] 
[   0.4974 ] Updating mb1-bct with firmware information
[   0.4981 ] tegrabct_v2 --chip 0x18 --mb1bct mb1_cold_boot_bct_MB1.bct --updatefwinfo flash.xml.bin
[   0.4987 ] MB1-BCT version: 0xe
[   0.4991 ] 
[   0.4991 ] Updating mb1-bct with storage information
[   0.4998 ] tegrabct_v2 --chip 0x18 --mb1bct mb1_cold_boot_bct_MB1.bct --updatestorageinfo flash.xml.bin
[   0.5013 ] MB1-BCT version: 0xe
[   0.5017 ] 
[   0.5025 ] tegrahost_v2 --align mb1_cold_boot_bct_MB1.bct
[   0.5032 ] 
[   0.5039 ] tegrahost_v2 --appendsigheader mb1_cold_boot_bct_MB1.bct zerosbk
[   0.5047 ] 
[   0.5057 ] tegrasign_v2 --key None --list mb1_cold_boot_bct_MB1_sigheader.bct_list.xml
[   0.5063 ] Assuming zero filled SBK key
[   0.5077 ] 
[   0.5086 ] tegrahost_v2 --updatesigheader mb1_cold_boot_bct_MB1_sigheader.bct.encrypt mb1_cold_boot_bct_MB1_sigheader.bct.hash zerosbk
[   0.5094 ] 
[   0.5095 ] Generating recovery mb1-bct
[   0.5102 ] tegrabct_v2 --chip 0x18 --mb1bct mb1_bct.cfg --sdram P3310_A00_8GB_Samsung_8GB_lpddr4_204Mhz_A02_l4t.cfg --misc tegra186-mb1-bct-misc-si-l4t.cfg --scr minimal_scr.cfg --pinmux tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg --pmc tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg --pmic tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg --brcommand tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg --prod tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg
[   0.5110 ] MB1-BCT version: 0xe
[   0.5112 ] Copying Sdram info from 2 to 3 set
[   0.5211 ] Copying Sdram info from 0 to 1 set
[   0.5212 ] Packing sdram param for instance[0]
[   0.5214 ] Packing sdram param for instance[1]
[   0.5215 ] Packing sdram param for instance[2]
[   0.5217 ] Packing sdram param for instance[3]

[   0.5218 ] Parsing config file :tegra186-mb1-bct-pinmux-quill-p3310-1000-c03.cfg 
[   0.5221 ] Appending platform config data of size :- 2904

[   0.5223 ] Parsing config file :minimal_scr.cfg 
[   0.5225 ] Appending platform config data of size :- 12240

[   0.5238 ] Parsing config file :tegra186-mb1-bct-pad-quill-p3310-1000-c03.cfg 
[   0.5241 ] Appending platform config data of size :- 24
[   0.5241 ] 
[   0.5241 ] Parsing config file :tegra186-mb1-bct-pmic-quill-p3310-1000-c04.cfg 
[   0.5241 ] Appending platform config data of size :- 708
[   0.5241 ] 
[   0.5241 ] Parsing config file :tegra186-mb1-bct-bootrom-quill-p3310-1000-c03.cfg 
[   0.5241 ] Appending platform config data of size :- 64
[   0.5242 ] 
[   0.5242 ] Parsing config file :tegra186-mb1-bct-prod-quill-p3310-1000-c03.cfg 
[   0.5242 ] Appending platform config data of size :- 1628
[   0.5242 ] 
[   0.5242 ] Updating mb1-bct with firmware information
[   0.5248 ] tegrabct_v2 --chip 0x18 --mb1bct mb1_bct_MB1.bct --updatefwinfo flash.xml.bin
[   0.5255 ] MB1-BCT version: 0xe
[   0.5258 ] 
[   0.5259 ] Updating mb1-bct with storage information
[   0.5265 ] tegrabct_v2 --chip 0x18 --mb1bct mb1_bct_MB1.bct --updatestorageinfo flash.xml.bin
[   0.5271 ] MB1-BCT version: 0xe
[   0.5274 ] 
[   0.5281 ] tegrahost_v2 --align mb1_bct_MB1.bct
[   0.5287 ] 
[   0.5295 ] tegrahost_v2 --appendsigheader mb1_bct_MB1.bct zerosbk
[   0.5304 ] 
[   0.5313 ] tegrasign_v2 --key None --list mb1_bct_MB1_sigheader.bct_list.xml
[   0.5320 ] Assuming zero filled SBK key
[   0.5334 ] 
[   0.5345 ] tegrahost_v2 --updatesigheader mb1_bct_MB1_sigheader.bct.encrypt mb1_bct_MB1_sigheader.bct.hash zerosbk
[   0.5353 ] 
[   0.5354 ] Copying signatures
[   0.5361 ] tegrahost_v2 --chip 0x18 --partitionlayout flash.xml.bin --updatesig images_list_signed.xml
[   0.5428 ] 
[   0.5429 ] Boot Rom communication
[   0.5437 ] tegrarcm_v2 --chip 0x18 --rcm rcm_list_signed.xml
[   0.5445 ] BootRom is not running
[   1.5416 ] 
[   1.5440 ] tegrarcm_v2 --isapplet
[   1.5462 ] Applet version 01.00.0000
[   1.5602 ] 
[   1.5603 ] Retrieving board information
[   1.5627 ] tegrarcm_v2 --oem platformdetails chip chip_info.bin
[   1.5648 ] Applet version 01.00.0000
[   1.5883 ] Saved platform info in chip_info.bin
[   1.5896 ] Chip minor revision: 2
[   1.5900 ] 
[   1.5900 ] Sending BCTs
[   1.5923 ] tegrarcm_v2 --download bct_bootrom br_bct_BR.bct --download bct_mb1 mb1_bct_MB1_sigheader.bct.encrypt
[   1.5942 ] Applet version 01.00.0000
[   1.6200 ] Sending bct_bootrom
[   1.6203 ] [................................................] 100%
[   1.6302 ] Sending bct_mb1
[   1.6359 ] [................................................] 100%
[   1.9998 ] 
[   1.9999 ] Generating blob
[   2.0024 ] tegrahost_v2 --align blob_nvtboot_recovery_cpu.bin
[   2.0046 ] 
[   2.0068 ] tegrahost_v2 --appendsigheader blob_nvtboot_recovery_cpu.bin zerosbk
[   2.0098 ] 
[   2.0127 ] tegrasign_v2 --key None --list blob_nvtboot_recovery_cpu_sigheader.bin_list.xml
[   2.0149 ] Assuming zero filled SBK key
[   2.0238 ] 
[   2.0248 ] tegrahost_v2 --updatesigheader blob_nvtboot_recovery_cpu_sigheader.bin.encrypt blob_nvtboot_recovery_cpu_sigheader.bin.hash zerosbk
[   2.0258 ] 
[   2.0268 ] tegrahost_v2 --align blob_nvtboot_recovery.bin
[   2.0277 ] 
[   2.0286 ] tegrahost_v2 --appendsigheader blob_nvtboot_recovery.bin zerosbk
[   2.0608 ] 
[   2.0637 ] tegrasign_v2 --key None --list blob_nvtboot_recovery_sigheader.bin_list.xml
[   2.0659 ] Assuming zero filled SBK key
[   2.0717 ] 
[   2.0728 ] tegrahost_v2 --updatesigheader blob_nvtboot_recovery_sigheader.bin.encrypt blob_nvtboot_recovery_sigheader.bin.hash zerosbk
[   2.0738 ] 
[   2.0747 ] tegrahost_v2 --align blob_preboot_d15_prod_cr.bin
[   2.0756 ] 
[   2.0764 ] tegrahost_v2 --appendsigheader blob_preboot_d15_prod_cr.bin zerosbk
[   2.0775 ] 
[   2.0786 ] tegrasign_v2 --key None --list blob_preboot_d15_prod_cr_sigheader.bin_list.xml
[   2.0794 ] Assuming zero filled SBK key
[   2.0815 ] 
[   2.0826 ] tegrahost_v2 --updatesigheader blob_preboot_d15_prod_cr_sigheader.bin.encrypt blob_preboot_d15_prod_cr_sigheader.bin.hash zerosbk
[   2.0837 ] 
[   2.0847 ] tegrahost_v2 --align blob_mce_mts_d15_prod_cr.bin
[   2.0856 ] 
[   2.0865 ] tegrahost_v2 --appendsigheader blob_mce_mts_d15_prod_cr.bin zerosbk
[   2.0907 ] 
[   2.0920 ] tegrasign_v2 --key None --list blob_mce_mts_d15_prod_cr_sigheader.bin_list.xml
[   2.0929 ] Assuming zero filled SBK key
[   2.1549 ] 
[   2.1560 ] tegrahost_v2 --updatesigheader blob_mce_mts_d15_prod_cr_sigheader.bin.encrypt blob_mce_mts_d15_prod_cr_sigheader.bin.hash zerosbk
[   2.1587 ] 
[   2.1600 ] tegrahost_v2 --align blob_bpmp.bin
[   2.1608 ] 
[   2.1616 ] tegrahost_v2 --appendsigheader blob_bpmp.bin zerosbk
[   2.1631 ] 
[   2.1640 ] tegrasign_v2 --key None --list blob_bpmp_sigheader.bin_list.xml
[   2.1648 ] Assuming zero filled SBK key
[   2.1776 ] 
[   2.1787 ] tegrahost_v2 --updatesigheader blob_bpmp_sigheader.bin.encrypt blob_bpmp_sigheader.bin.hash zerosbk
[   2.1801 ] 
[   2.1809 ] tegrahost_v2 --align blob_tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2.dtb
[   2.1818 ] 
[   2.1825 ] tegrahost_v2 --appendsigheader blob_tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2.dtb zerosbk
[   2.1839 ] 
[   2.1848 ] tegrasign_v2 --key None --list blob_tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2_sigheader.dtb_list.xml
[   2.1856 ] Assuming zero filled SBK key
[   2.1972 ] 
[   2.1983 ] tegrahost_v2 --updatesigheader blob_tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2_sigheader.dtb.encrypt blob_tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2_sigheader.dtb.hash zerosbk
[   2.1996 ] 
[   2.2004 ] tegrahost_v2 --align blob_tos.img
[   2.2012 ] 
[   2.2020 ] tegrahost_v2 --appendsigheader blob_tos.img zerosbk
[   2.2029 ] 
[   2.2038 ] tegrasign_v2 --key None --list blob_tos_sigheader.img_list.xml
[   2.2045 ] Assuming zero filled SBK key
[   2.2062 ] 
[   2.2071 ] tegrahost_v2 --updatesigheader blob_tos_sigheader.img.encrypt blob_tos_sigheader.img.hash zerosbk
[   2.2080 ] 
[   2.2088 ] tegrahost_v2 --align blob_eks.img
[   2.2096 ] 
[   2.2103 ] tegrahost_v2 --appendsigheader blob_eks.img zerosbk
[   2.2110 ] 
[   2.2119 ] tegrasign_v2 --key None --list blob_eks_sigheader.img_list.xml
[   2.2126 ] Assuming zero filled SBK key
[   2.2127 ] 
[   2.2137 ] tegrahost_v2 --updatesigheader blob_eks_sigheader.img.encrypt blob_eks_sigheader.img.hash zerosbk
[   2.2145 ] 
[   2.2153 ] tegrahost_v2 --align blob_tegra186-tx2-cti-ASG001-USB3.dtb
[   2.2160 ] 
[   2.2167 ] tegrahost_v2 --appendsigheader blob_tegra186-tx2-cti-ASG001-USB3.dtb zerosbk
[   2.2178 ] 
[   2.2187 ] tegrasign_v2 --key None --list blob_tegra186-tx2-cti-ASG001-USB3_sigheader.dtb_list.xml
[   2.2194 ] Assuming zero filled SBK key
[   2.2247 ] 
[   2.2257 ] tegrahost_v2 --updatesigheader blob_tegra186-tx2-cti-ASG001-USB3_sigheader.dtb.encrypt blob_tegra186-tx2-cti-ASG001-USB3_sigheader.dtb.hash zerosbk
[   2.2268 ] 
[   2.2277 ] tegrahost_v2 --generateblob blob.xml blob.bin
[   2.2285 ] number of images in blob are 9
[   2.2286 ] blobsize is 3662312
[   2.2287 ] Added binary blob_nvtboot_recovery_cpu_sigheader.bin.encrypt of size 184576
[   2.2296 ] Added binary blob_nvtboot_recovery_sigheader.bin.encrypt of size 78080
[   2.2299 ] Added binary blob_preboot_d15_prod_cr_sigheader.bin.encrypt of size 61472
[   2.2302 ] Added binary blob_mce_mts_d15_prod_cr_sigheader.bin.encrypt of size 2077088
[   2.2308 ] Added binary blob_bpmp_sigheader.bin.encrypt of size 528800
[   2.2312 ] Added binary blob_tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2_sigheader.dtb.encrypt of size 466160
[   2.2316 ] Added binary blob_tos_sigheader.img.encrypt of size 58880
[   2.2319 ] Added binary blob_eks_sigheader.img.encrypt of size 1488
[   2.2321 ] Added binary blob_tegra186-tx2-cti-ASG001-USB3_sigheader.dtb.encrypt of size 205616
[   2.2332 ] 
[   2.2333 ] Sending bootloader and pre-requisite binaries
[   2.2341 ] tegrarcm_v2 --download blob blob.bin
[   2.2348 ] Applet version 01.00.0000
[   2.2488 ] Sending blob
[   2.2488 ] [................................................] 100%
[   2.6658 ] 
[   2.6682 ] tegrarcm_v2 --boot recovery
[   2.6703 ] Applet version 01.00.0000
[   2.6855 ] 
[   2.6878 ] tegrarcm_v2 --isapplet
[   3.3167 ] 
[   3.3660 ] tegradevflash_v2 --iscpubl
[   3.3684 ] CPU Bootloader is not running on device.
[   3.3692 ] 
[   4.5652 ] Retrieving storage infomation
[   4.5674 ] tegrarcm_v2 --oem platformdetails storage storage_info.bin
[   4.5696 ] Applet is not running on device. Continue with Bootloader
[   4.5949 ] 
[   4.5959 ] tegradevflash_v2 --oem platformdetails storage storage_info.bin
[   4.5968 ] Bootloader version 01.00.0000
[   4.6073 ] Saved platform info in storage_info.bin
[   4.6133 ] 
[   4.6133 ] Flashing the device
[   4.6148 ] tegraparser_v2 --storageinfo storage_info.bin --generategpt --pt flash.xml.bin
[   4.6164 ] 
[   4.6171 ] tegradevflash_v2 --pt flash.xml.bin --create
[   4.6179 ] Bootloader version 01.00.0000
[   4.6199 ] Erasing sdmmc_boot: 3 ......... [Done]
[   4.6489 ] Writing partition secondary_gpt with gpt_secondary_0_3.bin
[   4.6500 ] [................................................] 100%

[   4.7104 ] Erasing sdmmc_user: 3 ......... [Done]
[   7.0215 ] Writing partition master_boot_record with mbr_1_3.bin
[   7.0223 ] [................................................] 100%
[   7.0301 ] Writing partition primary_gpt with gpt_primary_1_3.bin
[   7.0403 ] [................................................] 100%
[   7.0486 ] Writing partition secondary_gpt with gpt_secondary_1_3.bin
[   7.0640 ] [................................................] 100%

[   7.0874 ] Append 256 to mb1_prod.bin.encrypt
[   7.0879 ] Writing partition mb1 with mb1_prod.bin.encrypt
[   7.0886 ] [................................................] 100%
[   7.0988 ] Append 96 to spe_sigheader.bin.encrypt
[   7.1089 ] Writing partition spe-fw with spe_sigheader.bin.encrypt
[   7.1097 ] [................................................] 100%
[   7.1192 ] Append 480 to nvtboot_sigheader.bin.encrypt
[   7.1288 ] Writing partition mb2 with nvtboot_sigheader.bin.encrypt
[   7.1296 ] [................................................] 100%
[   7.1398 ] Append 480 to preboot_d15_prod_cr_sigheader.bin.encrypt
[   7.1475 ] Writing partition mts-preboot with preboot_d15_prod_cr_sigheader.bin.encrypt
[   7.1485 ] [................................................] 100%
[   7.1578 ] Writing partition master_boot_record with mbr_1_3.bin
[   7.1663 ] [................................................] 100%
[   7.1741 ] Writing partition APP with system.img
[   7.1783 ] [................................................] 100%
[ 155.9198 ] Append 96 to mce_mts_d15_prod_cr_sigheader.bin.encrypt
[ 155.9402 ] Writing partition mts-bootpack with mce_mts_d15_prod_cr_sigheader.bin.encrypt
[ 155.9413 ] [................................................] 100%
[ 156.0305 ] Append 80 to cboot_sigheader.bin.encrypt
[ 156.0494 ] Writing partition cpu-bootloader with cboot_sigheader.bin.encrypt
[ 156.0503 ] [................................................] 100%
[ 156.0656 ] Append 208 to tegra186-tx2-cti-ASG001-USB3_sigheader.dtb.encrypt
[ 156.0732 ] Writing partition bootloader-dtb with tegra186-tx2-cti-ASG001-USB3_sigheader.dtb.encrypt
[ 156.0745 ] [................................................] 100%
[ 156.0879 ] Writing partition secure-os with tos_sigheader.img.encrypt
[ 156.0955 ] [................................................] 100%
[ 156.1058 ] Append 48 to eks_sigheader.img.encrypt
[ 156.1115 ] Writing partition eks with eks_sigheader.img.encrypt
[ 156.1122 ] [................................................] 100%
[ 156.1200 ] Append 96 to bpmp_sigheader.bin.encrypt
[ 156.1242 ] Writing partition bpmp-fw with bpmp_sigheader.bin.encrypt
[ 156.1250 ] [................................................] 100%
[ 156.1486 ] Append 272 to tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2_sigheader.dtb.encrypt
[ 156.1607 ] Writing partition bpmp-fw-dtb with tegra186-a02-bpmp-quill-p3310-1000-c04-00-te770d-ucm2_sigheader.dtb.encrypt
[ 156.1623 ] [................................................] 100%
[ 156.1825 ] Append 320 to camera-rtcpu-sce_sigheader.bin.encrypt
[ 156.1928 ] Writing partition sce-fw with camera-rtcpu-sce_sigheader.bin.encrypt
[ 156.1938 ] [................................................] 100%
[ 156.2036 ] Append 432 to warmboot_wbheader.bin.encrypt
[ 156.2094 ] Writing partition sc7 with warmboot_wbheader.bin.encrypt
[ 156.2102 ] [................................................] 100%
[ 156.2181 ] Writing partition kernel with boot.img
[ 156.2266 ] [................................................] 100%
[ 156.2761 ] Append 96 to tegra186-tx2-cti-ASG001-USB3.dtb
[ 156.2878 ] Writing partition kernel-dtb with tegra186-tx2-cti-ASG001-USB3.dtb
[ 156.2887 ] [................................................] 100%
[ 156.3088 ] 
[ 156.3111 ] tegradevflash_v2 --write BCT br_bct_BR.bct
[ 156.3130 ] Bootloader version 01.00.0000
[ 156.3155 ] Writing partition BCT with br_bct_BR.bct
[ 156.3160 ] [................................................] 100%
[ 156.3627 ] 
[ 156.3715 ] tegradevflash_v2 --write MB1_BCT mb1_cold_boot_bct_MB1_sigheader.bct.encrypt
[ 156.3738 ] Bootloader version 01.00.0000
[ 156.3771 ] Writing partition MB1_BCT with mb1_cold_boot_bct_MB1_sigheader.bct.encrypt
[ 156.3781 ] [................................................] 100%
[ 156.4246 ] 
[ 156.4247 ] Flashing completed

[ 156.4248 ] Coldbooting the device
[ 156.4272 ] tegradevflash_v2 --reboot coldboot
[ 156.4294 ] Bootloader version 01.00.0000
[ 156.4365 ] 
*** The target t186ref has been flashed successfully. ***
Reset the board to boot from internal eMMC.

```
