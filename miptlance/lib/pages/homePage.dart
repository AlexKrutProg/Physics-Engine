// ignore_for_file: prefer_const_constructors
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:my_money_handler/services/auth.dart';
import 'package:my_money_handler/services/dataBase.dart';
import 'package:provider/provider.dart';
import 'personalPage.dart';
import 'settings.dart';
class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  int _selectedIndex = 1;

  void _setIndex(int index) {
    if (_selectedIndex == index) return;
    setState(() {
      _selectedIndex = index;
    });
  }

  static const List<Widget> _pages = <Widget>[
    Icon(
      Icons.call,
      size: 150,
    ),
    Icon(
      Icons.camera,
      size: 150,
    ),
    Icon(
      Icons.chat,
      size: 150,
    ),
  ];
  final AuthService _auth = AuthService();
  void handleClick(String value) {
    switch(value) {
      case 'Logout':
        _auth.signOut();
        break;
      case 'Settings':
        Navigator.pushNamed(context, '/settings');
        break;
      case 'personal page':
        Navigator.pushNamed(context, '/personalPage');
        break;
    }
  }
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("MiptLance"),
        centerTitle: true,
        actions: [
          PopupMenuButton<String>(
            onSelected: handleClick,
            itemBuilder: (BuildContext context) {
              return {'Settings','personal page','Logout'}.map((String choice) {
                return PopupMenuItem<String>(
                  value: choice,
                  child: Text(choice),
                );
              }).toList();
            },
          ),
          ],
      ),
      body: Center(
        child: _pages.elementAt(_selectedIndex), //New
      ),
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _selectedIndex,
        onTap: _setIndex,
        items: [
          BottomNavigationBarItem(
              icon: Icon(Icons.local_offer), label: "create offer"),
          BottomNavigationBarItem(
              icon: Icon(Icons.home), label: "home"),
          BottomNavigationBarItem(
              icon: Icon(Icons.people_rounded), label: "get job"),
        ],
      ),
    );
  }
}
