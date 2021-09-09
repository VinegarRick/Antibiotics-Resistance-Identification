# Antibiotics Resistance Identification and Analysis

Installation:

Download ResFinder from https://bitbucket.org/genomicepidemiology/resfinder and follow the installation intructions. Add the ResFinder
folder "genomicepidemiology-resfinder-fc8fb36d9f7d" to the directory. 

The INSTALL_DB script does not work properly as it requires access rights to the linked database. Instead, the ResFinder database can be 
obtained from here: https://bitbucket.org/genomicepidemiology/resfinderdb. Add the database folder "genomicepidemiology-resfinder_db-fa3f073985f5" 
to the resfinder folder. 

As per the instructions, running brew.sh will also install Blast. However, this ResFinder is compatible only with the legacy blast package, specifically 2.2.26, which can be 
obtained here: ftp://ftp.ncbi.nlm.nih.gov/blast/executables/legacy/2.2.26/. Add the Blast folder "blast-2.2.26" to the resfinder folder. 

bwa, samtools, and bedtools must be installed.

Compilation:

Compile the files get_vulnerabilities.cpp and merge_strains.cpp with the below respective commands:

"g++ get_vulnerabilities.cpp -o get_vulnerabilities -std=c++11"
"g++ merge_strains.cpp -o merge_strains -std=c++11"

Usage:

The script takes a variable amount of input files. For one fasta file, the script utilizes ResFinder to to detect antibiotic
vulnerabilities and resistances. This is run as follows:

./script file.fdna

For two fasta files and an annotation gff file for one of the two fasta files, the script aligns the first fasta file to the second 
fasta file and utilizes bedtools to take the intersect of the alignment and the first fasta file's annotation file in order to obtain 
a fasta file "intersect.fna" containing genes sequences in the second fasta file not present in the first. ResFinder is then used 
to detect antibiotic vulnerabilities shared between the two fasta files and and all resistances. This is run as follows:

./script file1.fna file2.fna file2.gff

For three or more fasta files, the script simply utilizes ResFinder to detect antibiotic vulnerabilities shared by all input fasta files
and all total resistances. This is run as follows:

./script file1.fna file2.fna file3.fna ... file10.fna
