import 'package:flutter/material.dart';
import 'package:my_money_handler/services/userDataBase.dart';
import 'package:my_money_handler/userClasses/UserIdentifier.dart';
import 'package:provider/provider.dart';
import 'package:my_money_handler/userClasses/UserData.dart';
class PersonalPage extends StatefulWidget {
  const PersonalPage({Key? key}) : super(key: key);

  @override
  _PersonalPageState createState() => _PersonalPageState();
}

class _PersonalPageState extends State<PersonalPage> {
  @override
  Widget build(BuildContext context) {
    FutureBuilder<String>(
      future: fetchData, // async work
      builder: (BuildContext context, AsyncSnapshot<String> snapshot) {
        switch (snapshot.connectionState) {
          case ConnectionState.waiting: return Text('Loading....');
          default:
            if (snapshot.hasError)
              return Text('Error: ${snapshot.error}');
            else {
              userData
              return Scaffold(

              );
            }

        }
      },
    )
  }
}
