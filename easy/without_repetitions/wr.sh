#!/bin/sh

sed 's/\(.\)\1\+/\1/g' $1
