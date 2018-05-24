
#include <iostream>
#include "namegen.hpp"

int main()
{
	std::cout << "ciao!" << std::endl;
	
	auto s = merak::new_lexic(
		"pitagora pisone callimaco filippo filottete ermete giapeto titano ariel umbriel ganimede andromeda marte giove carlo piero doriano giuliano protagora anassagora anassimene eraclito erone giasone gianluca callisto venere rea europa dione eurialo euripide sofocle ulisse agamennone achille eratostene eubea lesbo atene pandora oplonte uroboro ettore patroclo euclonte eschilo tucidide omero eneade ilio elio iperione", 
		10);
		
	std::cout << s << std::endl;
}