#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <string>

class Timer {
public:
	std::vector<std::chrono::nanoseconds> segments;

	Timer() {}
	~Timer() {}

	void start() {
		begin = std::chrono::steady_clock::now();
	}
	void stop() {
		end = std::chrono::steady_clock::now();

		segments.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin));
	}
	void print_seg() {
		std::cout << "Timer:" << std::endl;
		for (int i = 0; i < segments.size(); i++) {
			std::cout << "     [" << i << "] " << segments[i].count() << " ns" << std::endl;
		}
	}
private:
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point end;
};