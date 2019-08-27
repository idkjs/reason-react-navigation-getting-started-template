open ReactNative;
open ReactNavigation;
module HomeScreen = {
  open Expo;

  let styles =
    Style.(
      StyleSheet.create({
        "container":
          style(
            ~flex=1.,
            ~justifyContent=`center,
            ~alignItems=`center,
            ~backgroundColor="#F5FCFF",
            (),
          ),
        "instructions": style(~textAlign=`center, ~color="#ffffff", ()),
      })
    );

  [@react.component]
  let make = () => {
    <View style=styles##container>
        <Text style=styles##instructions>
          {React.string("Home Screen")}
        </Text>
    </View>;
  };
};
module AppNavigator = {
  let routes = {"Home": HomeScreen.make};

  let navigator = StackNavigator.(make(routes));
};
module AppContainer =
  AppContainer.Make({
    type screenProps = {. "someProp": int};

    let navigator = AppNavigator.navigator;
  });
[@react.component]
let make = () => {
  let screenProps = {"someProp": 42};
  <AppContainer screenProps />;
};