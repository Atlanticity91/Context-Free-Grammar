#include "CFGFile.hpp"

std::vector< Rule > LoadRules( std::string path ) {
	std::vector< Rule > result;

	if ( path != "" && path != " " ) {
		std::ifstream file = std::ifstream( path );
		std::string text = "";

		while ( !file.eof( ) ) {
			text = "";
			getline( file, text, '\n' );

			if ( !file.eof( ) ) {
				Rule rule;
				rule.Size = 0;
				std::stringstream ss = std::stringstream( text );

				while ( !ss.eof( ) ) {
					ss >> text;

					if ( !ss.eof( ) ) {
						rule.Words.push_back( text );
						rule.Size++;

						if ( text[ 0 ] == '#' )
							rule.PivotCount++;
					} else 
						break;
				}

				result.push_back( rule );
			}
		}

		file.close( );
	}

	return result;
}

std::vector< Category > LoadVocabulary( std::string path ) {
	std::vector< Category > result;

	if ( path != "" && path != " " ) {
		std::ifstream file = std::ifstream( path );
		Category category;
		std::string text;

		while ( !file.eof( ) ) {
			category = Category( );

			file >> category.Token;
			if ( file.eof( ) )
				break;

			file >> category.Size;
			if ( file.eof( ) )
				break;

			category.Words = std::vector< std::string >( category.Size );

			for ( int index = 0; index < category.Size; index++ ) {
				file >> text;

				if ( !file.eof( ) ) 
					category.Words[ index ] = text;
				else
					break;
			}

			result.push_back( category );
		}

		file.close( );
	}

	return result;
}