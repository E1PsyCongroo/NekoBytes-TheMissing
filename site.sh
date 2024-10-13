#!/usr/bin/env bash
WORK_DIR=$(pwd)
SITE_DIR="$WORK_DIR/static"
SOURCE=("$WORK_DIR/index.html" "$WORK_DIR/Lectures")
mkdir -p "$SITE_DIR"
cp -r "${SOURCE[@]}" "$SITE_DIR"

CODE_DIR="$WORK_DIR/Others/Codes"
JEKLLY_TOOL_DIR="$WORK_DIR/Tools/ghpages-mini-fileserver"
cp -r "$CODE_DIR" "$JEKLLY_TOOL_DIR/resources"
bash "$JEKLLY_TOOL_DIR/prenodes.sh"
cd "$JEKLLY_TOOL_DIR" && bundle install && bundle exec jekyll build --baseurl "$1"
cp -r "$JEKLLY_TOOL_DIR/_site" "$SITE_DIR"
