#pragma once
#include "MyCalc.h"

MyCalc::MyCalc() {
	//creating all the CalculatorOperation objects and setting their keys
	//the keys are vectors of strings so we initialize all of them.
	
	//+
	AddOperation *addo = new AddOperation();
	vector<string> addops(4);
	addops[0] = "+";
	addops[1] = "+=";
	addops[2] = "add";
	addops[3] = "Add";
	this->m_map[addops] = addo;
	//-
	SubOperation *subo = new SubOperation();
	vector<string> subops(4);
	subops[0] = "-";
	subops[1] = "-=";
	subops[2] = "sub";
	subops[3] = "Sub";
	this->m_map[subops] = subo;
	//*
	MulOperation *mulo = new MulOperation();
	vector<string> mulops(4);
	mulops[0] = "*";
	mulops[1] = "*=";
	mulops[2] = "mul";
	mulops[3] = "Mul";
	this->m_map[mulops] = mulo;
	// / (divide)
	DivOperation *divo = new DivOperation();
	vector<string> divops(4);
	divops[0] = "/";
	divops[1] = "/=";
	divops[2] = "div";
	divops[3] = "Div";
	this->m_map[divops] = divo;
	//Sqrt
	SqrtOperation *sqrto = new SqrtOperation();
	vector<string> sqrtops(2);
	sqrtops[0] = "sqrt";
	sqrtops[1] = "Sqrt";
	this->m_map[sqrtops] = sqrto;
	//Power ^
	PowOperation *powo = new PowOperation();
	vector<string> powops(4);
	powops[0] = "^";
	powops[1] = "^=";
	powops[2] = "pow";
	powops[3] = "Pow";
	this->m_map[powops] = powo;
	//Factorial !
	FactorialOperation *faco = new FactorialOperation();
	vector<string> facops(3);
	facops[0] = "fac";
	facops[1] = "Fac";
	facops[2] = "!";
	this->m_map[facops] = faco;
	//Modulo %
	ModuloOperation *modo = new ModuloOperation();
	vector<string> modops(4);
	modops[0] = "%";
	modops[1] = "%=";
	modops[2] = "mod";
	modops[3] = "Mod";
	this->m_map[modops] = modo;
	//Int (casting)
	IntOperation *into = new IntOperation();
	vector<string> intops(2);
	intops[0] = "int";
	intops[1] = "Int";
	this->m_map[intops] = into;
}

MyCalc::~MyCalc() {
	//iterates through the map and deletes every CalculatorOperation object.
	for (map<vector<string>, CalculatorOperation*>::iterator it = this->m_map.begin(); it != this->m_map.end(); ++it) {
		delete it->second;
	}
}