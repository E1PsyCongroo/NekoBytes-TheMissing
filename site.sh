#!/usr/bin/env bash
WORK_DIR=$(pwd)
SITE_DIR="$WORK_DIR/static"
SOURCE=("$WORK_DIR/index.html" "$WORK_DIR/Lectures")
mkdir -p "$SITE_DIR"
cp -r "${SOURCE[@]}" "$SITE_DIR"

JEKLLY_TOOL_DIR="$WORK_DIR/Tools/ghpages-mini-fileserver"
RESOURCE="$JEKLLY_TOOL_DIR/resources"
mkdir -p "$RESOURCE"
find "$WORK_DIR/Lectures" -type d -name "Codes" -exec cp -r "{}" "$RESOURCE" \;
bash "$JEKLLY_TOOL_DIR/prenodes.sh"
cd "$JEKLLY_TOOL_DIR" && bundle exec jekyll build --baseurl "$1"
cp -r "$JEKLLY_TOOL_DIR/_site" "$SITE_DIR"
