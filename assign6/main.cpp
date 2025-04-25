/*
 * CS106L Assignment 6: Explore Courses
 * Created by Haven Whitney with modifications by Jacob Roberts-Baca and Fabio
 * Ibanez.
 */

#include <algorithm>
#include <iterator>
#include <optional>
#include <type_traits>
#include <vector>

/** STUDENT_TODO: You will need to include a relevant header file here! */

#include "autograder/utils.hpp"

/**
 * A course. This should be familiar from Assignment 1!
 */
struct Course {
	std::string title;
	std::string number_of_units;
	std::string quarter;

	/**
	 * You don't have to ignore this anymore! We're defining the `==` operator for
	 * the Course struct.
	 */
	bool operator==(const Course& other) const {
		return title == other.title && number_of_units == other.number_of_units && quarter == other.quarter;
	}
};
;

class CourseDatabase {
public:
	CourseDatabase(std::string filename) {
		auto lines = read_lines(filename);
		std::ranges::transform(lines,
		    std::back_inserter(courses),
		    [](std::string line) {
			    auto parts = split(line, ',');
			    return Course { .title = parts[0], .number_of_units = parts[1], .quarter = parts[2] };
		    });
	}

	/**
	 * Finds a course in the database with the given title, if it exists.
	 * @param course_title The title of the course to find.
	 * @return You will need to figure this out!
	 */
	std::optional<Course> find_course(std::string course_title) {
		/* STUDENT_TODO: Implement this method! You will need to change the return
		 * type. */
		for (auto& course : courses) {
			if (course.title == course_title) {
				return course;
			}
		}
		return {};
	}

private:
	std::vector<Course> courses;
};

int main(int argc, char* argv[]) {
	static_assert(
	    !std::is_same_v<std::invoke_result_t<decltype(&CourseDatabase::find_course),
	                        CourseDatabase, std::string>,
	        FillMeIn>,
	    "You must change the return type of CourseDatabase::find_course to "
	    "something other than FillMeIn.");

	if (argc == 2) {
		CourseDatabase db("autograder/courses.csv");
		auto           op_course = db.find_course(argv[1]);

		/********************************************************
		STUDENT_TODO: Populate the output string with the right information to print
		Please pay special attention to the README here
		********************************************************/

		std::string output = op_course
		                         .transform([](auto& course) { return "Found course: " + course.title + "," + course.number_of_units + "," + course.quarter; })
		                         .or_else([]() { return std::optional<std::string>("Course not found."); })
		                         .value();
		/* STUDENT_TODO */

		/********************************************************
		 DO NOT MODIFY ANYTHING BELOW THIS LINE PLEASE
		********************************************************/

		std::cout << output << '\n';
		return 0;
	}

	return run_autograder();
}
