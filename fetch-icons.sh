if [ ! -d images ]; then
  mkdir images
fi
curl -so pim-osx.icns http://pim-files.s3.amazonaws.com/pim-osx.icns
curl -so images/pim.svg http://pim-files.s3.amazonaws.com/pim.svg

