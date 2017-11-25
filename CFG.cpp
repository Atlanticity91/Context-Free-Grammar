#include "CFG.hpp"

std::string Process( Rule &rule, std::vector< Category > &categories ) {
	int index = 0;
	int pivot_id = 0;
	std::string output = "";

	while ( index < rule.Size ) {
		if ( rule.Words[ index ][ 0 ] != '#' )
			output += rule.Words[ index ] + ' ';
		else {
			pivot_id = Findcategory( categories, rule.Words[ index ] );

			if ( pivot_id > -1 )
				output += GetWord( categories[ pivot_id ] ) + ' ';
			else
				output += "#error# ";
		}

		index++;
	}

	return output;
}

void DisplayRuleArray( std::vector< Rule > &rules ) {
	for ( int index = 0; index < rules.size( ); index++ ) {
		std::cout << "Rule : \n";
		std::cout << "\tPivot count : " << rules[ index ].PivotCount << '\n';
		std::cout << "\tValue : ";

		for ( int word = 0; word < rules[ index ].Words.size( ); word++ )
			std::cout << rules[ index ].Words[ word ] << ' ';

		std::cout << "\n\n";
 	}
}

std::string GetWord( Category &category ) {
	return category.Words[ rand( ) % category.Size ];
}

int Findcategory( std::vector< Category > categories, std::string pivot ) {
	pivot.erase( pivot.begin( ) );

	if ( pivot[ pivot.size( ) - 1 ] == '.' )
		pivot.erase( pivot.end( ) - 1 );
	
	for ( int index = 0; index < categories.size( ); index++ ) {
		if ( categories[ index ].Token != pivot )
			continue;
		else
			return index;
	}

	return -1;
}

void DiplayCategoryArray( std::vector< Category > &categories ) {
	for ( int index = 0; index < categories.size( ); index++ ) {
		std::cout << categories[ index ].Token << " : \n";

		for ( int i = 0; i < categories[ index ].Size; i++ )
			std::cout << '\t' << categories[ index ].Words[ i ] << '\n';

		std::cout << '\n';
	}
}