using System;

class Test
{
    public int a { get; set; }
    public int b { get; set; }
}

class Program
{
    static void Main(string[] args)
    {
        // int n1 = 50;
        // int n2;
        // n2 = 100;
        //
        // long sum = n1 + n2;
        //
        // Console.WriteLine(sum);

        string name = "C#";
        //Console.WriteLine(name);

        string name2 = new string("java");
        //Console.WriteLine(name2);

        Test t = new Test();
        t.a = 10;
        t.b = 20;
        
        Console.WriteLine(t);       // 내부적으로 t.ToString() 호출
                                    // 오버라이딩 안 하면 클래스 이름만 출력됨 (Test)
                                    // 자바는 클래스이름@해시, C#은 그냥 클래스이름
    }
}