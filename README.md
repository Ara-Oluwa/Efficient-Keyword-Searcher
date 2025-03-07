Authors: Ara-Oluwa Jacob, Olivia McClam

Contributors: Swarthmore CS Department

About: Imagine reading a large PDF document, such as a textbook, and you want to find the most relevant pages where priority queues are described. 
A typical search tool in a PDF reader will tell you where your search term appears in order of page number, but this might not be what you want.
The pages where your search phrase appears multiple times are more likely to be the ones you want to read. 
In this situation, we prefer a prioritized list, where pages with the most occurrences of your search term appear first.
This program reads in documents and then repeatedly searches the document for particular keywords. 
For each search, the program efficiently finds the ten most relevant pages that contain that keyword.

To accomplish this, we built two new implementations of the Dictionary ADT: LinearDictionary and HashTable.
Then, created a KeywordSearcher class that employs the Dictionary implementations along with an existing implementation
of a PriorityQueue to quickly search documents for keywords.
