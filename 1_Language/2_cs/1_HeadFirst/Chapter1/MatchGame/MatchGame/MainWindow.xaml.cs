using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Threading;

namespace MatchGame
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            timer.Interval = TimeSpan.FromSeconds(.1);
            timer.Tick += Timer_Tick;

            SetUpGame();
        }

        private void SetUpGame()
        {
            List<string> animalEmoji = new List<string>()
            { 
                "🐒", "🐒",
                "🐕‍🦺", "🐕‍🦺",
                "🦝", "🦝",
                "🐇", "🐇",
                "🐖", "🐖",
                "🐘", "🐘",
                "🐭", "🐭",
                "🦔", "🦔"
            };

            Random random = new Random();
            foreach (var textBlock in mainGrid.Children.OfType<TextBlock>())
            {
                if (textBlock.Name != "TimeTextBlock")
                {
                    textBlock.Visibility = Visibility.Visible;
                    int index = random.Next(animalEmoji.Count);
                    string nextEmoji = animalEmoji[index];
                    textBlock.Text = nextEmoji;
                    animalEmoji.RemoveAt(index);
                }
            }
            timer.Start();
            tenthsOfSecondsElapsed = 0;
            matchsFound = 0;
        }

        private TextBlock lastTextBlockClicked;
        private bool isLastTextBlockClicked = false;

        private void TextBlock_MouseDown(object sender, MouseButtonEventArgs e)
        {
            TextBlock textBlock = sender as TextBlock;

            if (isLastTextBlockClicked == false)
            {
                textBlock.Visibility = Visibility.Hidden;
                lastTextBlockClicked = textBlock;
                isLastTextBlockClicked = true;
            }
            else if (lastTextBlockClicked.Text == textBlock.Text)
            {
                matchsFound++;
                textBlock.Visibility = Visibility.Hidden;
                isLastTextBlockClicked = false;
            }
            else
            {
                lastTextBlockClicked.Visibility = Visibility.Visible;
                isLastTextBlockClicked = false;
            }
        }

        DispatcherTimer timer = new DispatcherTimer();
        int tenthsOfSecondsElapsed;
        int matchsFound;

        private void Timer_Tick(object sender, EventArgs e)
        {
            tenthsOfSecondsElapsed++;
            TimeTextBlock.Text = (tenthsOfSecondsElapsed / 10f).ToString("0.0s");
            if (matchsFound == 8)
            {
                timer.Stop();
                TimeTextBlock.Text = TimeTextBlock.Text + " - Play again?";
            }
        }

        private void TimeTextBlock_MouseDown(object sender, MouseButtonEventArgs e)
        { 
            if (matchsFound == 8)
            {
                SetUpGame();
            }
        }
    }
}
