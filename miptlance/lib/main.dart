import 'package:flutter/material.dart';
import 'package:my_money_handler/wrapper.dart';
import 'pages/signUpPage.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:provider/provider.dart';
import 'package:my_money_handler/services/auth.dart';
import 'package:my_money_handler/userClasses/UserIdentifier.dart';
import 'pages/settings.dart';
import 'pages/personalPage.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(
    StreamProvider<UserIdentifier?>.value(
      value: AuthService().user,
      initialData: null,
      child: MaterialApp(
        home: Wrapper(),
        routes: {
          '/signUp': (context) => const SignUpPage(),
          '/settings': (context) => SettingsPage(),
          '/personalPage': (context) => PersonalPage(),
        },
        theme: ThemeData(
          brightness: Brightness.light,
          primaryColor: Colors.blue,
          focusColor: Colors.blue,
          backgroundColor: Colors.blue,
          fontFamily: 'MainFont',
          textTheme: const TextTheme(
            bodyText1: TextStyle(
                color: Colors.white, fontFamily: 'MainFont', fontSize: 22),
            bodyText2: TextStyle(
                fontSize: 20.0, fontFamily: 'MainFont', color: Colors.green),
          ),
        ),
      ),
    ),
  );
}
