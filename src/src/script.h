/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#pragma once

using namespace std;

void ScriptMain();
extern int RDR2selectedPlayer;

void debug(const char* text);
void debug(string text);
void debug(Vector3 position);
void debug(float f);
void debug(int n);
void debug(bool b);
void debug(Hash hash);
void showSubtitle(const char* text);
void showSubtitle(string text);
void showSubtitle(int n);
void showSubtitle(float f);
void showSubtitle(bool b);
void showSubtitle(Hash hash);
void logPlayerPos();