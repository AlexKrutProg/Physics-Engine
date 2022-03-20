import 'package:flutter/material.dart';
import 'package:my_money_handler/services/userDataBase.dart';
import 'package:my_money_handler/services/auth.dart';

class SignUpPage extends StatefulWidget {
  const SignUpPage({Key? key}) : super(key: key);

  @override
  _SignUpPageState createState() => _SignUpPageState();
}

class _SignUpPageState extends State<SignUpPage> {
  final _emailController = TextEditingController();
  final _passwordController = TextEditingController();
  final _repeatPasswordController = TextEditingController();
  final _key = GlobalKey<FormState>();
  final _auth = AuthService();

  @override
  void dispose() {
    // TODO: implement dispose
    super.dispose();
    _emailController.dispose();
    _passwordController.dispose();
    _repeatPasswordController.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).backgroundColor,
      ),
      body: Center(
        child: Container(
          width: 300,
          child: Column(
            children: [
              const Spacer(
                flex: 1,
              ),
              Text(
                'Registration',
                style: Theme.of(context).textTheme.headline4,
              ),
              const Spacer(flex: 1),
              Form(
                key: _key,
                child: Column(
                  children: [
                    TextFormField(
                      validator: (value) {
                        return value == null || value.isEmpty
                            ? 'Please enter valid email'
                            : null;
                      },
                      controller: _emailController,
                      decoration: InputDecoration(
                        labelText: 'email',
                        prefixIcon: Icon(Icons.email,
                            color: Theme.of(context).primaryColor),
                      ),
                    ),
                    TextFormField(
                      validator: (value) {
                        return _repeatPasswordController.text !=
                                _passwordController.text
                            ? 'Passwords do not match '
                            : null;
                      },
                      obscureText: true,
                      controller: _passwordController,
                      decoration: InputDecoration(
                        labelText: 'Password',
                        prefixIcon: Icon(Icons.email,
                            color: Theme.of(context).primaryColor),
                      ),
                    ),
                    TextFormField(
                      validator: (value) {
                        return _repeatPasswordController.text !=
                                _passwordController.text
                            ? 'Passwords do not match '
                            : null;
                      },
                      obscureText: true,
                      controller: _repeatPasswordController,
                      decoration: InputDecoration(
                        labelText: 'Repeat password',
                        prefixIcon: Icon(Icons.email,
                            color: Theme.of(context).primaryColor),
                      ),
                    ),
                  ],
                ),
              ),
              ButtonBar(
                children: [
                  ElevatedButton(
                    style: ButtonStyle(
                      backgroundColor:
                          MaterialStateProperty.all(Theme.of(context).primaryColor),
                    ),
                    onPressed: () async {
                      if (_key.currentState!.validate()) {
                         final user = await _auth.registerWithEmailAndPassword(
                                _emailController.text,
                                _passwordController.text);
                         await UserDataBaseService(uid: user.uid).CreateUserData();
                      }
                    },
                    child: Text('Submit'),
                  ),
                ],
              ),
              const Spacer(
                flex: 2,
              ),
              const SizedBox(
                height: 50,
                child: Image(
                  image: AssetImage('assets/logo.png'),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
