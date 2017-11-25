#include "CFGFile.hpp"

/**
 * main function
 * @note : Main entry of the program.
 * @author : ALVES Quentin
 * @return : An int.
 **/
int main( int argc, char **argv ) {
	// Init the random.
	srand( time( NULL ) );

	// Load rules and vocabulary.
	std::vector< Rule > rules = LoadRules( "Text/Rules.rls" );
	std::vector< Category > vocs = LoadVocabulary( "Text/Vocabulary.wds" );

	// Display rules and vocabulary.
	DisplayRuleArray( rules );
	DiplayCategoryArray( vocs );

	// Generate a bunch of sentence.
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 8; j++ )
			std::cout << Process( rules[ i ], vocs ) << '\n';
	}

	return 0;
}