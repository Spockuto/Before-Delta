import urllib2
import bs4
url = raw_input("Enter the url: ")
res = urllib2.urlopen(url)
data = res.read()
soup = bs4.BeautifulSoup(data)
soup2 = soup.findAll('span',{'class':'selling-price omniture-field'})
main = soup2[0].get_text()
coststr = str(main)
temp=''
for i in coststr :
	if(47<ord(i)<58):
		temp=temp+i
rate = int(temp)
print rate