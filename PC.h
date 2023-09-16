#pragma once
#include<iostream>
#include"Devices.h"
using namespace std;

// клас комп'ютер  
class PC {
	shared_ptr <Box>       box;
	shared_ptr <Processor> processor;
	shared_ptr <MainBoard> mainBoard;
	shared_ptr <Hdd>       hdd;
	shared_ptr <Memory>    memory;
public:
	PC() {
		box = nullptr;
		processor = nullptr;
		mainBoard = nullptr;
		hdd = nullptr;
		memory = nullptr;
	}
	virtual ~PC() {
	}
	shared_ptr <Box> GetBox() {
		return (box);
	}
	void SetBox(shared_ptr <Box> pBox) {
		box = (pBox);
	}
	shared_ptr < Processor> GetProcessor() {
		return (processor);
	}
	void SetProcessor(shared_ptr < Processor> pProcessor) {
		processor = (pProcessor);
	}
	shared_ptr < MainBoard> GetMainBoard() {
		return (mainBoard);
	}
	void SetMainBoard(shared_ptr < MainBoard> pMainBoard) {
		mainBoard = (pMainBoard);
	}
	shared_ptr <Hdd> GetHdd() {
		return (hdd);
	}
	void SetHdd(shared_ptr <Hdd> pHdd) {
		hdd = (pHdd);
	}
	shared_ptr <Memory> GetMemory() {
		return (memory);
	}
	void SetMemory(shared_ptr <Memory> pMemory) {
		memory = (pMemory);
	}
};