rlt = str(sum([int(i) for i in input()]))
rlt_dic = {'0':'zero','1':"one",'2':"two",'3':"three",'4':'four','5':"five",
            '6':"six",'7':"seven",'8':'eight','9':"nine"}
rlt = ' '.join([rlt_dic[i] for i in rlt])
print(rlt)