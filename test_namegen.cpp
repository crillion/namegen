
#include <iostream>
#include "namegen.hpp"

void test1()
{
	auto s = merak::new_lexic(
		"pitagora pisone callimaco filippo filottete ermete giapeto titano ariel umbriel ganimede andromeda marte giove carlo piero doriano giuliano protagora anassagora anassimene eraclito erone giasone gianluca callisto venere rea europa dione eurialo euripide sofocle ulisse agamennone achille eratostene eubea lesbo atene pandora oplonte uroboro ettore patroclo euclonte eschilo tucidide omero eneade ilio elio iperione", 
		10);
		
	std::cout << s << std::endl;	
}

void test2()
{
	std::cout << "specify how many new names generate : ";
	int n = 0;
	std::cin >> n;	
	std::cout << "please insert some words or names just separed by space\n";


	std::vector<std::string> items;
	
    std::copy(
		std::istream_iterator<std::string>(std::cin),
		std::istream_iterator<std::string>(),
		std::back_inserter(items));

/*		
	std::stringstream oss;
		
	std::ostream_iterator<std::string> out(oss, " ");
	
	std::copy(
		std::begin(items),
		std::end(items),
		out);
	
	std::string names = oss.str();
	
	auto new_names = merak::new_lexic(names, n);
//	std::cout << new_names << std::endl;

	std::cout << n << "\n";
	std::cout << names << "\n" << std::endl;
*/	
}

int main()
{	
	test2();
}