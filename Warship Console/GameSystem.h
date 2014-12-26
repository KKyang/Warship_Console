#pragma once
#include "stdafx.h"
#include "string"

void MainWindowsystem(int optselect[1], int PressPauseCheck[1], int count, int Player[15][15], int Enemy[15][15]);
void setdefault(int Player[15][15], int Enemy[15][15]);
void Shipcolor(int Shiptype);
void putShip(int Enemy[15][15]);
void playerShip(int Player[15][15]);
void Blood(int x, int y);
void BloodCut(int x, int y);
void ShowLoadShip(int Player[15][15], int Enemy[15][15]);
void PlayerAttack(int Enemy[15][15], int PressPauseCheck[1]);
void EnemyAI(int Player[15][15]);
