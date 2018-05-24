
#ifndef _RANDOM_HELP_RANDOM_HELP_HPP
#define _RANDOM_HELP_RANDOM_HELP_HPP

#include <ctime>
#include <functional>
#include <random>

namespace random_help
{
	class rand_int_simple 
	{
		public:
			rand_int_simple(int lo, int hi) : 
				r(std::bind(std::uniform_int_distribution<>(lo, hi), std::default_random_engine()))
			{
			}
			int operator()() const 
			{ 
				return r();
			}
		private:
			std::function<int()> r;
	};

	class rand_int 
	{
		public:
			rand_int(int lo, int hi) : 
				r(std::bind(std::uniform_int_distribution<>(lo, hi), std::default_random_engine()))
			{
			}
			
			rand_int(int lo, int hi, bool seed_with_time, int seed = 0)
			{
				std::default_random_engine eng;
				
				if(seed_with_time) eng.seed(std::default_random_engine::result_type(std::time(nullptr)));
				else eng.seed(seed);
					
				r = std::bind(std::uniform_int_distribution<>(lo, hi), eng);
			}
			
			int operator()() const 
			{ 
				return r();
			}
		private:

			std::function<int()> r;
	};
	
	class rand_real
	{
		public:
			rand_real(double lo, double hi) : 
				r(std::bind(std::uniform_real_distribution<>(lo, hi), std::default_random_engine()))
			{
			}
			
			rand_real(double lo, double hi, bool seed_with_time, int seed = 0)
			{
				std::default_random_engine eng;
				
				if(seed_with_time) eng.seed(std::default_random_engine::result_type(std::time(nullptr)));
				else eng.seed(seed);
					
				r = std::bind(std::uniform_real_distribution<>(lo, hi), eng);
			}
			
			double operator()() const 
			{ 
				return r();
			}
		private:

			std::function<double()> r;		
	};	
}

#endif