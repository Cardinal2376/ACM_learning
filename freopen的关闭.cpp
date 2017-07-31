
    freopen("in.txt", "r", stdin);
    fclose(stdin);
    freopen("CON", "r", stdin);
    int m;
    cin >> m;
    cout << m;

/*
windows 下对拍
:again
D:\cb-work4\gen\bin\Debug\gen.exe
D:\cb-work4\duiA\bin\Debug\duiA.exe
D:\cb-work4\duiB\bin\Debug\duiB.exe
fc C:\Users\admin\Desktop\duipai\out1.txt C:\Users\admin\Desktop\duipai\out2.txt
if not errorlevel 1 goto again
pause

linux 下对拍
if diff test.out test.ans;then
echo AC
else
echo WA
exit 0
fi
done
*/