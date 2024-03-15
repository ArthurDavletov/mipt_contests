#!/bin/bash
while [ $# -gt 1 ]; do
  case "$1" in
    "--input_folder")
      shift
      input_folder=$1;;
    "--extension")
      shift
      extension=$1;;
    "--backup_folder")
      shift
      backup_folder=$1;;
    "--backup_archive_name")
      shift
      backup_archive_name=$1;;
  esac
  shift
done

# echo "Input Folder: $input_folder"
# echo "Extension: $extension"
# echo "Backup Folder: $backup_folder"
# echo "Backup Archive Name: $backup_archive_name"


# $1 -- path, $2 -- folder to copy
function RecursionCopyFiles() {
  for file in "$1"/*; do
    if [ -d "$file" ]; then
      RecursionCopyFiles "$file" "$2"
    elif [ "${file##*.}" = "$extension" ]; then
      base_name="${file##*/}"
      filename="${base_name%.*}"
      extension="${base_name##*.}"
      dest_file=$2/"${filename}.$extension"
      counter=1
      while [ -e "$dest_file" ]; do
        dest_file="$2/${filename}${counter}.$extension"
        ((counter++))
      done
      cp "$file" "$dest_file"
      # echo $file $dest_file
    fi
  done
} 

mkdir -p "$backup_folder"
RecursionCopyFiles "$input_folder" "$backup_folder"
tar -zcf $backup_archive_name $backup_folder
# rm -rf $backup_folder
echo "done"
