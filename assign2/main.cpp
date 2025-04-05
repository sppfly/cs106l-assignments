/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob
 * Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <exception>
#include <fstream>
#include <iostream>
#include <queue>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

#include "utils.h"

std::string kYourName = "Nova M"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names
 * as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the
 * function below it) to use a `std::unordered_set` instead. If you do so, make
 * sure to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
	std::unordered_set<std::string> res{};
	std::ifstream file{filename};
	if (!file.is_open()) {
		std::cerr << "error opening file" << '\n';
		std::terminate();
	}
	std::string line;

	while (std::getline(file, line)) {
		res.insert(line);
	}
	return res;
}

std::string get_initial(const std::string name) {

	// auto initials = name
	//     | std::ranges::views::split(' ') // Split into words
	//     | std::ranges::views::transform([](auto &&word) {
	//         return *word.begin(); // Get the first character of each word
	//       });
	// std::string result;
	// for (char initial : initials) {
	//   result += initial;
	// }
	std::string result;
	std::string word;
	std::vector<std::string> words;
	std::stringstream ss{name};
	while (std::getline(ss, word, ' ')) {
		result += word[0];
	}

	return result;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as
 * this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string *>
find_matches(std::string name, std::unordered_set<std::string> &students) {
	std::queue<const std::string *> res{};
	std::string to_match = get_initial(name);
	std::cout << to_match << '\n';

	for (auto &&student : students) {
		auto init = get_initial(student);
		if (to_match == init) {
			res.push(&student);
		}
	}
	return res;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true
 * match!
 *
 * You can implement this function however you'd like, but try to do something a
 * bit more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string *> &matches) {
	if (matches.empty()) {
		return "NO MATCHES FOUND.";
	}
	return *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
