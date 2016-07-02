#!/bin/bash

DIRECTORY="src/"

if [ $# -ne 1 ]; then
  (>&2 echo "Invalid number of Arguments")
  (>&2 echo "Usage: <$0> ClassName")
  exit 1
fi

CPP_FILE="$DIRECTORY/$1.cpp"
HPP_FILE="$DIRECTORY/$1.hpp"

if [ -f $CPP_FILE ]; then
  (>&2 echo "Error \"$1.cpp\" exits.")
  exit 2
fi

if [ -f $HPP_FILE ]; then
  (>&2 echo "Error \"$1.hpp\" exits.")
  exit 3
fi

echo -e "#include \"$1.hpp\"\n" > $CPP_FILE

IFNDEF=$(echo $1 | tr '[:lower:]' '[:upper:]')
echo -e "#ifndef __""$IFNDEF""_HPP__" > $HPP_FILE
echo -e "#define __""$IFNDEF""_HPP__" >> $HPP_FILE
echo -e "\nclass $1 {" >> $HPP_FILE
echo -e "  private:\n  public:" >> $HPP_FILE
echo -e "};" >> $HPP_FILE
echo -e "#endif // __""$IFNDEF""_HPP__" >> $HPP_FILE
