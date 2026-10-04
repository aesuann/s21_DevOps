#!/bin/bash
set -e

REMOTE="rin2@192.168.252.7"
SSH_OPTS="-o StrictHostKeyChecking=accept-new -o BatchMode=yes"

echo "Copying artifacts to $REMOTE"
scp $SSH_OPTS src/cat/s21_cat src/grep/s21_grep "$REMOTE:/tmp/"

echo "Installing to /usr/local/bin"
ssh $SSH_OPTS "$REMOTE" "sudo install -m 755 /tmp/s21_cat /tmp/s21_grep /usr/local/bin/ && rm -f /tmp/s21_cat /tmp/s21_grep"

echo "Checking result"
ssh $SSH_OPTS "$REMOTE" "ls -l /usr/local/bin/s21_cat /usr/local/bin/s21_grep"

echo "Deploy finished"