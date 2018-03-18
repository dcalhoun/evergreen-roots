/* TODO: Create render prop component to fetch/load/error. http://bit.ly/2BIHLXC */
type action =
  | SetListings(ListingData.items);

type state = {listings: ListingData.items};

let component = ReasonReact.reducerComponent("Store");

let make = (~render, _children) => {
  ...component,
  initialState: () => {listings: [||]},
  reducer: (action, _state) =>
    switch (action) {
    | SetListings(listings) => ReasonReact.Update({listings: listings})
    },
  render: self => {
    let dispatch = action => self.reduce(payload => action(payload));
    render(dispatch, self.state);
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~render=jsProps##render, [||])
  );
