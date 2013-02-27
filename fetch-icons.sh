if [ ! -d images ]; then
  mkdir images
fi
curl -so floim-osx.icns http://floim-files.s3.amazonaws.com/floim-osx.icns
curl -so images/floim.svg http://floim-files.s3.amazonaws.com/floim.svg

