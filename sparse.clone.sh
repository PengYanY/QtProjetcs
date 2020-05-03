#!/bin/sh
git init
git remote add origin https://github.com/PengYanY/QtProjetcs.git
git config core.sparsecheckout true
echo "QPainterTest" >> .git/info/sparse-checkout
git pull origin master
