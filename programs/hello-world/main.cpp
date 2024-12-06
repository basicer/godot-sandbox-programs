#include <api.hpp>

static Variant hello_world() {
	return "Hello, world!";
}
static Variant print_string(String str) {
	printf("String: %s\n", str.utf8().c_str());
	fflush(stdout);
	return Nil;
}

static long fib(long n, long acc, long prev)
{
	if (n == 0)
		return acc;
	else
		return fib(n - 1, prev + acc, acc);
}

static Variant fibonacci(int n) {
	return fib(n, 0, 1);
}

static int meaning_of_life = 42;
int main() {
	print("Hello, world!");

	// Add public API
	ADD_API_FUNCTION(hello_world, "String", "", "Returns the string 'Hello, world!'");
	ADD_API_FUNCTION(print_string, "void", "String str", "Prints a string to the console");
	ADD_API_FUNCTION(fibonacci, "long", "int n", "Calculates the nth Fibonacci number");

	// Add a property
	add_property("meaning_of_life", Variant::Type::INT, 42,
		[]() -> Variant { return meaning_of_life; },
		[](Variant value) -> Variant { meaning_of_life = value; print("Set to: ", meaning_of_life); return Nil; });

	halt();
}
