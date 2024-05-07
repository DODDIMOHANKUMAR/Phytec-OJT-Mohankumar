1) Boot the board and create a new file (wpa_supplicant.conf) in data directory 

$ root@ruggedboard-a5d2x: cd /data/
$ root@ruggedboard-a5d2x:/data# vi wpa_supplicant.conf

2) Add the below lines in the conf file
------
ctrl_interface=/var/run/wpa_supplicant
ctrl_interface_group=0
update_config=1

network={
                ssid="PHYTEC_777VR1"
                proto=WPA2
                key_mgmt=WPA-PSK
                psk="777vr1@phytec"
}
----------


3)Give the below command to driver intializaton

$ root@ruggedboard-a5d2x:~# modprobe wilc-sdio

4) Give the below comnmand to activation of wpa_cli 

$ root@ruggedboard-a5d2x:~# wpa_supplicant -B -Dnl80211 -i wlan0 -c /data/wpa_supplicant.conf

5) Run the udhcpc command to assign the ip address to wlan0 node

$ root@ruggedboard-a5d2x:~# udhcpc -i wlan0

6) Ping the google.com to test the wifi

$ root@ruggedboard-a5d2x:~# ping google.com


