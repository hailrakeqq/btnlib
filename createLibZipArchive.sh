#!/bin/bash

fileh="src/btnlib.h"
filec="src/btnlib.c"

archive_name="btnlib.zip"

zip "$archive_name" "$fileh" "$filec"

echo "Archive $archive_name was successfully created."