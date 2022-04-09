#!/bin/bash
command="$1 < $2"
eval "$command"
read LINE