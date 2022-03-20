import 'package:flutter/material.dart';
import 'package:my_money_handler/pages/homePage.dart';
import 'package:my_money_handler/pages/signInPage.dart';
import 'package:my_money_handler/userClasses/UserIdentifier.dart';
import 'package:provider/provider.dart';

class Wrapper extends StatelessWidget {
  const Wrapper({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final user = Provider.of<UserIdentifier?>(context);
    //return home or signInPage
    if (user!=null) {
      if (Navigator.canPop(context))
        Navigator.pop(context);
      return HomePage();
    } else
      return SignInPage();
  }
}
