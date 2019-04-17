# Comment-Removal-FULL-SOLUTION
A sneaky student has gotten hold of the instructor’s solution to a programming assignment written in Conbol.  The student wants to submit the program as his own.  To make it look like a student program, he wants to remove all the comments.  You are to write a program that reads a text file called comment.txt containing the Conbol program source code and display the program text without the comments.

There are two types of comments in Conbol.  Comments can begin with two exclamation characters, !! and end with two exclamation characters, !!  This form of comment can extend across multiple lines or only a part of a line.  All characters in the between !! and !! should be removed, including the !! and !! and any end of line characters inside the comment.  The other form of a comment starts with exclamation dash, !- and continues to the end of the line.  When you remove a comment of this form, eliminate the !- and all following characters. You should leave the end of line character.

Conbol programs have string constants that are in “double quotes”.   If the start characters of a comment (either !- or !!) are inside a string constant, then they are part of the string constant and do not represent the start of a comment.  String constants never span more than one line.  It is possible that double quotes may appear inside a comment.  If they do, they should be removed just like any other character.  You may assume that the input program is syntactically correct.

Example input from comment.txt
public class { !!  My commented program !!
	public static void main(String[] unused) { !- main method
		String thing = "fake !- comment "; 
		thing = !! short comment !! "real stuff";
		!!  long
			comment
		!!
		thing = "!! " + "!! "; !- weird
		int num = 5 / 6;
	}
}

Example output
public class { 
	public static void main(String[] unused) { 
		String thing = "fake !- comment "; 
		thing =  "real stuff";
		
		thing = "!! " + "!! "; 
		int num = 5 / 6;
	}
}
