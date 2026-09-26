#!/bin/sh
set -eu
here=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
mkdir -p "$here/bin"
for f in startup.ccr startup.cct menu.ccr menu.cct book.ccr book.cct; do
  cp "$here/../nxdk-widget011/bin/$f" "$here/bin/$f"
done
