#!/bin/bash
echo "*.*~"  > .gitignore
echo "*.[oa]"  >> .gitignore
echo "*.html"  >> .gitignore
git check-ignore -v * | awk '{print $2}'
