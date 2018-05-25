// namegen.hpp

#ifndef _NAMEGEN_HPP
#define _NAMEGEN_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
//#include <boost/tokenizer.hpp>
#include "random_help.hpp"

namespace merak {
	
template<class seq_type>
std::string seq_to_string(const seq_type& seq, const std::string& separator = ", ")
{
	std::stringstream os;
	std::ostream_iterator<typename seq_type::value_type> oi(os, separator.c_str());
	std::copy(std::begin(seq), std::end(seq), oi);
	
	std::string s = os.str();
	
	return s.substr(0, s.size() - separator.size());
}
/*
bool contains(const std::string& s1, const std::string& s2)
{
	return s1.find(s2, 0) != std::string::npos;
}
*/
template<class ITEM_CONTAINER, class ITEM>
bool contains(const ITEM_CONTAINER& container, const ITEM& item)
{
	return std::find(std::begin(container), std::end(container), item) != std::end(container);
}

std::vector<std::string> separe(const std::string& content, const std::string& separator)
{
/*	
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> sep(separator.c_str());
	tokenizer tokens(content, sep);
	
	std::vector<std::string> items;
	
	std::copy(std::begin(tokens), std::end(tokens), std::back_inserter(items));
	
	return items;
*/
//std::cout << "content : " << content << "\n";
    std::istringstream iss(content);
	
	std::vector<std::string> items;
	
    std::copy(
		std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(items));

//std::cout << "items.size() : " << items.size() << "\n";
		
	return items;
}

std::vector<std::string> common_initials(
	const std::vector<std::string>& source_);

std::vector<std::string> common_finals(
	const std::vector<std::string>& source_);

std::vector<std::string> middle_parts(
	const std::vector<std::string>& names_, 
	const std::vector<std::string>& prefixes_, 
	const std::vector<std::string>& subfixes_);

std::string new_lexic(
	const std::string& lexic_, 
	const int& n_);

std::vector<std::string> new_words(
	int n_,
	const std::vector<std::string>& initials_,
	const std::vector<std::string>& middles_,
	const std::vector<std::string>& finals_);

bool begins_with(const std::string& s1_, const std::string& s2_);

bool ends_with(const std::string& s1_, const std::string& s2_);

std::vector<std::string> common_initials(
	const std::vector<std::string>& source_)
{

	typedef std::vector<std::string> source_type;

	source_type result;

	// per ogni stringa *i1 nel vector _source
	for(
		source_type::const_iterator 
			i1(source_.begin()),
			e(source_.end()); 
		i1 != e; 
		++i1) {
		
		// per ogni stringa *i2 successiva a *i1 
		// nel vector _source
		for(
			source_type::const_iterator 
				i2(i1 + 1); 
			i2 != e; 
			++i2) {

			std::string new_entry;

			// per ogni carattere *j1 in *i1 e *j2 in *i2
			for(
				std::string::const_iterator 
					j1(i1->begin()), 
					e1(i1->end()),
					j2(i2->begin()),
					e2(i2->end());
				j1 != e1 && 
				j2 != e2;
				++j1, 
				++j2) {

				// se *j1 e *j2 sono uguali
				if(*j1 == *j2) {

					// inserisci *j1 in str1
					new_entry += *j1;

				// altrimenti esci dal ciclo
				} else break;

			} // for(
			  //     j1 = (*i1).begin(), j2 = (*i2).begin();
			  //     j1 < (*i1).end() && j2 < (*i2).end();
			  //     ++j1, ++j2)


			// se la string str1 contiene almeno un carattere
			if(
				!new_entry.empty() &&
				!merak::contains(result, new_entry)) {

					// inserisci str1 in _answer
					result.push_back(new_entry);

			} // if(!contains(_answer, str1)) 
		
		} // for(i2 = i1 + 1; i2 < _source.end(); ++i2)

	} // for(i1 = _source.begin(); i1 < _source.end(); ++i1)

	return result;

}

std::vector<std::string> common_finals(const std::vector<std::string>& source_)
{

	typedef std::vector<std::string> source_type;

	source_type result;

//	list<char> v1;
//	string str1;

	// per ogni stringa *i1 nel vector _source
	for(
		source_type::const_iterator 
			i1(source_.begin()),
			e(source_.end()); 
		i1 != e; 
		++i1) {
		
		// per ogni stringa *i2 successiva a *i1 
		// nel vector _source
		for(
			source_type::const_iterator
				i2(i1 + 1); 
			i2 != e; 
			++i2) {

			std::string new_entry;

			// per ogni carattere *j1 in *i1 e *j2 in *i2
			for(
				std::string::const_iterator
					j1(i1->end() - 1), 
					j2(i2->end() - 1);
				j1 >= i1->begin() && 
				j2 >= i2->begin();
				--j1, 
				--j2) {

				// se *j1 e *j2 sono uguali
				if(*j1 == *j2) {

					// inserisci *j1 in str1
					new_entry.insert(new_entry.begin(), *j1);

				// altrimenti esci dal ciclo
				} else break;

			} // for(
			  //     j1 = (*i1).begin(), j2 = (*i2).begin();
			  //     j1 < (*i1).end() && j2 < (*i2).end();
			  //     ++j1, ++j2)


			// se il vector v1 contiene almeno un carattere
			if(
				!new_entry.empty() &&
				!merak::contains(result, new_entry)) {

					// inserisci str1 in result
					result.push_back(new_entry);

			} // if(str1.size() > 0)
		
		} // for(i2 = i1 + 1; i2 < _source.end(); ++i2)

	} // for(i1 = _source.begin(); i1 < _source.end(); ++i1)

	return result;

}

void left_part(std::vector<std::string>& _names, std::vector<std::string>& _left_part, std::vector<std::string>& _right_part)
{
	
	std::vector<std::string>::iterator i1;

}

std::vector<std::string> middle_parts(
	const std::vector<std::string>& names_, 
	const std::vector<std::string>& prefixes_, 
	const std::vector<std::string>& subfixes_)
{

	typedef std::vector<std::string> source_type;

	source_type result;

	// per ogni nome *i1
	for(
		source_type::const_iterator
			i1(names_.begin()),
			e1(names_.end()); 
		i1 != e1; 
		++i1) {

		// per ogni prefisso *i2
		for(
			source_type::const_iterator
				i2(prefixes_.begin()),
				e2(prefixes_.end()); 
			i2 != e2; 
			++i2) {

			// se *i1 comincia con *i2
			if(begins_with(*i1, *i2)) {

				// per ogni suffisso *i3
				for(
					source_type::const_iterator
						i3(subfixes_.begin()),
						e3(subfixes_.end()); 
					i3 != e3; 
					++i3) {

					// se *i1 finisce con *i3
					if(ends_with(*i1, *i3)) {

						// se *i1 contiene effettivamente una parte in mezzo
						if(i1->size() > i2->size() + i3->size()) {

							std::string new_entry;

							new_entry.append(
								i1->begin() + i2->size(),
								i1->begin() + i1->size() - i3->size());

							if(
								!new_entry.empty() &&
								!merak::contains(result, new_entry)) {
	
								result.push_back(new_entry);

							}

						} // if((*i1).size() > (*i2).size() + (*i3).size())

					} // if(ends_with(*i1, *i3))

				} // for(i3 = _suffissi.begin(); i3 < _suffissi.end(); ++i3)

			} // if(begins_with(*i1, *i2))

		} // for(i2 = _prefissi.begin(); i2 < _prefissi.end(); ++i2)

	} // for(i1 = _names.begin(); i1 < _names.end(); ++i1)

	return result;

}

std::string new_lexic(
	const std::string& lexic_, 
	const int& n_)
{

	typedef std::vector<std::string> source_type;

	source_type lexic_words(merak::separe(lexic_, " "));
	source_type initials(common_initials(lexic_words));

	std::string s_initials(merak::seq_to_string(initials, " "));

	source_type finals(common_finals(lexic_words));
	source_type middles(middle_parts(lexic_words, initials, finals));
	source_type new_lexic_words(new_words(n_, initials, middles, finals));
	std::string result(merak::seq_to_string(new_lexic_words, " "));
	return result;

}

std::vector<std::string> new_words(
	int n_,
	const std::vector<std::string>& initials_,
	const std::vector<std::string>& middles_,
	const std::vector<std::string>& finals_)
{

	std::vector<std::string> result;

	int s_in(initials_.size());
	int s_mid(middles_.size());
	int s_fin(finals_.size());
	
	auto rgen1 = random_help::rand_int(0, s_in, true);
	auto rgen2 = random_help::rand_int(0, s_mid, true);
	auto rgen3 = random_help::rand_int(0, s_fin, true);
	

	for(
		int i(0); 
		i < n_; 
		++i) {

		std::string str1;

		int r1 = rgen1();
		int r2 = rgen2();
		int r3 = rgen3();

		str1.append(initials_[r1]);
		str1.append(middles_[r2]);
		str1.append(finals_[r3]);

		if(!merak::contains(result, str1)) {

			result.push_back(str1);

		} // if(!contains(_answer, str1))

	} // for(i = 0; i < _num; ++i)

	return result;

}

bool begins_with(const std::string& s1_, const std::string& s2_)
{
	if(s1_.size() < s2_.size()) {
		return false;
	}
	for(
		std::string::const_iterator
			i1(s1_.begin()),
			i2(s2_.begin()),
			e2(s2_.end());
		i2 != e2;
		++i1,
		++i2) {
		if(*i1 != *i2) {
			return false;
		}
	}
	return true;
}

bool ends_with(const std::string& s1_, const std::string& s2_)
{
	if(s1_.size() < s2_.size())
	{
		return false;
	}
	for(
		std::string::const_reverse_iterator
			i1(s1_.rbegin()),
			i2(s2_.rbegin()),
			e2(s2_.rend());
		i2 != e2;
		++i1,
		++i2) {
		if(*i1 != *i2) {
			return false;
		}
	}
	return true;
}

}

#endif