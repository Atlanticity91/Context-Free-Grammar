#ifndef _CFG_FILE_HPP_
#define _CFG_FILE_HPP_

	#include "CFG.hpp"

	/**
	 * LoadRules function
	 * @note : Load sentence rules from file.
	 * @author : ALVES Quentin
	 * @param path[in] : Path to the query rules file.
	 * @return : A std::vector< Rule >.
	 **/
	std::vector< Rule > LoadRules( std::string path );

	/**
	 * LoadVocabulary function
	 * @note : Load sentence vocabulary from file.
	 * @author : ALVES Quentin
	 * @param path[in] : Path to the query vocabulary file.
	 * @return : A std::vector< Category >.
	 **/
	std::vector< Category > LoadVocabulary( std::string path );

#endif