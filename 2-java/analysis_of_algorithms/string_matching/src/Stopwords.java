package busranin_analiz_projesi;

import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Pattern;

public  class Stopwords {


	String[] stopwords = {"a", "as" , "able" , "about" , "above" ,  "across",
			//"the" , "what"
			"after" , "again" , "against" , "to" , "the" , "all" , "allows" , "almost" , "alone" ,
			"along" , "already" , "also" , "although" , "always" , "amongst" , "an" , "and" , 
			"another" , "any" , "anybody", "anyone", "anything", "anyway" ,"appear" , "aren't" ,
			"around", "as" , "aside" , "ask" , "asking" , "at" , "available", "away", 
			"be" , "because" , "becomes" , "becoming", "been" , "before" , "behind" , "being" , 
			"believe" , "below" , "beside" , "besides" , "best" , "better" , "between" , "beyond" , 
			"both" , "but", "by" , "c'mon" , "can" , "can't" , "cannot" , "causes" , "changes" , 
			"clearly" , "come" , "comes" , "contain" , "containing" , "contains" , "could" , 
			"couldn't" , "course" , "definitely", "despite", "did", "didn't" , "different",
			"do" , "does" , "doesn't" , "doing" , "don't" , "done" , "down" , "during", 
			"each" , "eight" , "either" , "else" , "else" , "enough" , "even" , "ever" , 
			"every" , "everybody" , "everything" , "everywhere" , "exactly" ,
			"far" ,  "first" , "five" , "following" , "follows" , "for" , "forth" , "four" , "from" ,
			"further" , 
			"get" , "gets" ,"getting" , "gives" , "go" , "goes" , "going" , "gone" , "got" , "greetings" ,
			"had" , "hadn't" , "happens" , "hardly" , "has" , "has" , "hasn't" , "have" , "haven't" ,
			"having" , "he" , "he's" , "hello" , "help" , "her" , "here" , "herself" , "him"  , "himself" ,
			"his" , "how" , "however" , 
			"i" , "i'd" , "i'll" , "i'm" , "i've" , "if" , "ignored" , "in" , "inc" , "inner" , "instead" ,
			"into" , "is" , "isnt" , "it" , "it'd" , "its" , "it's" , "itself" ,
			"just" ,
			"keep" , "keeps" , "kept" , "know" , "knows" , "known" , 
			"last" , "later" , "less" , "lets" , "like" , "liked" , "little" , "look" , "looking" , "looks" ,
			"maybe" , "me" , "mean" , "more" , "most" , "much" , "must" , "my" , "myself" ,
			"name", "near" , "nearly" , "need" , "neither" , "never" , "new" , "next" , "no" , "nobody" ,          
			"none", 
			//"noone" , //no one
			"normally" , "not" , "nothing" , "novel" , "now" , "nowhere" ,
			"obviously" , "of" , "off" , "often" , "oh" , "okay" , "old" , "on" , "once" , "one" , "only" , 
			"onto" , "or" , "other" , "others" , "our" , "out" , "outside" , "over" , "own" ,
			"particular" , "perhaps" , "placed" , "please" , "possible" , 
			"really" , "regards" , "right" , "said" , "same" , "saw" , "say" , "saying" , "saying" ,  "see" , 
			"seeing" , "seem" , "seemed" , "seems" , "seen" , "sensible" , "serious" , "seven" , "several" ,
			"she" , "should" , "shouldn't" , "since" , "six" , "so" , "some" , "somebody" , "somehow" , 
			"someone" , "something" , "sometimes" , "somewhere" , "soon" , "sorry" , "still" , "such" , 
			"sure" , 
			"take" , "taken" , "tell" , "than" , "thank" , "thanks" , "that" , "that's" , "the" , "their" ,
			"them" , "then" , "there" , "there's" , "they" , "they'd" , "they're" , "think" , "third" , 
			"this" , "those" , "though" , "three" , "through" , "throughout" , "to" , "together" , "too" , 
			"took" , "towards" , "tries" , "try" , "trying" , "two" , 
			"under" , "until" , "up", "upon" , "used" , "using" , 
			"various" , "very" , 
			"want" , "was" , "wasn't" , "way" , "we" , "we'd" , "well" , "we're" , "we've" , "welcome" , "well" ,
			"well" , "went" , "were" , "what" , "what's" , "whatever" , "when" , "where" , "whether" , "which" ,
			"while" , "who" , "whole" , "whose" , "why" , "will" , "willing" , "with" , "within" , "without" , 
			"won't" , "wonder" , "would" , 
			"yes" , "yet" , "you" , "you'd" , "you'll" , "you're" , "you've" , "your" , "yourself" ,"?" , "" , 
			"." , "," ,"-" ,"..." , "!","color", "him"

	};

	String[] punctuation = {"?", "," ,"-" ,"..." , "!","\"","(",")" };



	public String Stopword_remover(String st) {
		for (int i = 0; i < stopwords.length; i++) {
			st = st.replaceAll(Pattern.quote(" " + stopwords[i] + " ")," ");	
		}
		return st;
	}




	public String noktalama(String st) {
		for (int i = 0; i < punctuation.length; i++) {
			st = st.replaceAll(Pattern.quote(punctuation[i])," ");	
			st = st.replaceAll(Pattern.quote(" " + punctuation[i])," ");	
			st = st.replaceAll(Pattern.quote(punctuation[i] + " ")," ");	
			st = st.replaceAll(Pattern.quote(" " + punctuation[i] + " ")," ");	
		}
		return st;
	}




	public ArrayList<ArrayList<String>> Stopword_remover2(ArrayList<ArrayList<String>> l) {



		for (int i = 0; i < l.size(); i++) {
			for (int j = 0; j < stopwords.length; j++) {
				Collections.replaceAll(l.get(i), stopwords[j], "");
			}
		}

		return l;

	}


}