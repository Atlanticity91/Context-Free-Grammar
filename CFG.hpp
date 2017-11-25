#ifndef _CONTEXT_FREE_GRAMMAR_HPP_
#define _CONTEXT_FREE_GRAMMAR_HPP_
	
	// Include C header's
	extern "C" {
		#include <stdlib.h>
		#include <time.h>
	}

	// Include C++ header's
	#include <iostream>
	#include <fstream>
	#include <sstream>
	#include <vector>

	/**
	 * Rule struct
	 * @author : ALVES Quentin
	 * @field Size : Count of word who compose the rule.
	 * @field PivotCount : Count of pivot inside the rule.
	 * @field Words : Array of all words who compose the rule.
	 **/
	typedef struct {

		int Size;
		int PivotCount;
		std::vector< std::string > Words;

	} Rule;

	/** 
	 * Category struct
	 * @author : ALVES Quentin
	 * @field Size : Count of word of the category.
	 * @field Token : Token value of the category.
	 * @field Words : All possible words of the category.
	 **/
	typedef struct {

		int Size;
		std::string Token;
		std::vector< std::string > Words;

	} Category;

	/**
	 * Process function
	 * @note : Generate a sentence based on a rule and vocabulary.
	 * @author : ALVES Quentin
	 * @param rule[in] : The rule used to produce the sentence.
	 * @param categories[in] : Vocabulary used to produce the sentence.
	 * @return : A string.
	 **/
	std::string Process( Rule &rule, std::vector< Category > &categories );

	/**
	 * DisplayRuleArray method
	 * @note : Display the list of all rules can be used to generate sentence.
	 * @author : ALVES Quentin
	 * @param rules[in] : List of all rules.
	 **/
	void DisplayRuleArray( std::vector< Rule > &rules );

	/**
	 * GetWord function
	 * @note : Get a random word of a category.
	 * @author : ALVES Quentin
	 * @param category[in] : Based category of the word.
	 * @return : A string.
	 **/
	std::string GetWord( Category &category );

	/**
	 * Findcategory function
	 * @note : Find the index of a category inside the category list; return -1 if no 
	 *		   category found.
	 * @author : ALVES Quentin
	 * @param categories[in] : List of all categories.
	 * @param pivot[in] : Token of the query category.
	 * @return : An int.
	 **/
	int Findcategory( std::vector< Category > categories, std::string pivot );

	/**
	 * DiplayCategoryArray method
	 * @note : Display the list of all categories can be used to generate sentence.
	 * @author : ALVES Quentin
	 * @param categories[in] : List of all categories.
	 **/
	void DiplayCategoryArray( std::vector< Category > &categories );

#endif