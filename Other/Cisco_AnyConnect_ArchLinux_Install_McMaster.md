# Cisco AnyConnect on ArchLinux for McMaster University

If you needed to work from home and wanted to use a better vpn client then you can always try `openconnect`

```
$ sudo openconnect --authgroup="Connect from Home" -g vpnusers sslvpn.mcmaster.ca
```

Notice that we needed to specify both the authgroup and the user group!

If openconnect does not work as intended, then you may continue reading

## Download the AnyConnect Client 

Download the anyconnect-linux package from the McMaster UTS website for linux currently available here: https://softdepot.mcmaster.ca/anyconnect-linux64-4.6.04056-predeploy-k9.tar.gz

Please note that the anyconnect client is not freely available to be downloaded and is only provided by organizations that use the software.

Note the directory where the tar.gz openconnect client is saved in. For the sake of example I will be using `/home/user/Downloads/`

## Download AUR Package

Download a snapshot of the `cisco-anyconnect` package on the AUR. Once downloaded extract it as follows

```
$ sudo tar -xvf cisco-anyconnect.tar.gz
```

## PKGBUILD Edits

Inside the `cisco-anyconnect` folder edit the `PKGBUILD` and perform the following actions:

On the line where it says `_source` set it to tarball

```
_source="tarball"
```

Change the package version to the one you downloaded (usually in the name of the client tar.gz downloaded).

```
pkgver=4.6.04046
```

On the line where it says `source=(file://...` replace the path of the file to the one you noted earlier

```
source=("file:///home/user/Downloads/${_filename}" ... 
```

On the line where it says `sha256sums` insert the string "SKIP" into the sums

```
sha256sums=("SKIP"
            '9d37640195b0fa4ffb073e1b006b4b9546595f7bd3b25a4fe9a0d43a75cd57b8'
            'dcc7a5dcbe4387f3e4a2a3f260b4197faf1b79adddf0d4dad3a02bc6041effa6'
            '0fcd62bd5d734c239bb7bda7c7e7791b9b8d76a019d2b42ff74caa998e7e9733'
            'b7c65a236e671d3eb527a3377e22b66018c450d726f71fa6344530a75255dac7')
```

On the line where it says `for lib in ...` remove "libboost_chrono.so" or any other binary that does not exist in the `vpn` directory in the client installer.

## Build the package

As usual make sure you are in the correct directory of the PKGBUILD then run

```
$ makepkg -sci
```

This should install the client with no problems or if there are problems then you probably forgot to remove the shared library files (`.so` files) or perhaps I forgot a step.

## Post build

Now make sure to enable the vpnagentd service

```
$ sudo systemctl enable --now vpnagentd
```

Now we need to modify the `AnyConnectLocalPolicy.xml`.

```
$ cd /opt/cisco/anyconnect
```

and you should be able to find the file mentioned above. Inside it modify the "BypassDownloader" from "true" to "false".

```
<BypassDownloader>false</BypassDownloader>
```


Edit the `.desktop` entry in `/usr/share/applications/cisco-anyconnect.desktop` where you modify the `exec` line to

```
Exec=gksudo -k -u root /opt/cisco/anyconnect/bin/vpnui
```

This will now ensure the application will run as root.

It would be best to restart the PC now (I had to or the following steps would not work)

## Running the client

The `.desktop` files should now be saved in `/usr/share/applications` directory so we can try and start the application via `gtk-launch`.

```
$ gtk-launch cisco-anyconnect.desktop
```

This should bring up the client. Follow the steps outlined on the Mcmaster UTS page and connect to the VPN. 

Once on the VPN, disconnect and make sure you now have the `McMasterProfile2012.xml` profile downloaded in `/opt/cisco/anyconnect/profiles`.

If any problem arrises where you get a "file move error", try restarting your PC and trying again. 
