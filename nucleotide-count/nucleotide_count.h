#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace dna {
	
	using namespace std;

	class counter;
};

class dna::counter {
private:
	map<char, int> m_Count;
public:
	counter(const string strStrand):
		m_Count({ { 'A', 0 }, { 'T', 0 }, { 'C', 0 }, { 'G', 0 } })
	{
		for (auto letter : strStrand)
			m_Count[letter]++;
	}

	int count(char chNucleotide) const {
		try{ return m_Count.at(chNucleotide); }
		catch (out_of_range){
			throw invalid_argument("Invalid input: " + chNucleotide);
		}
	}

	map<char, int> nucleotide_counts() const {
		return m_Count;
	}
};

#endif