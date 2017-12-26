let str = ReasonReact.stringToElement;

module Option = {
  let component = ReasonReact.statelessComponent("Option");
  let make = (~value, ~label=value, _children) => {
    ...component,
    render: (_self) => <option value> (str(label)) </option>
  };
};

let component = ReasonReact.statelessComponent("Select");

let make =
    (
      ~name: string,
      ~label: string,
      ~placeholder: string={js|Please select…|js},
      children
    ) => {
  let sContainer =
    ReactDOMRe.Style.make(
      ~display="inline-block",
      ~marginBottom="1rem",
      ~position="relative",
      ~width="100%",
      ()
    );
  let sLabel =
    ReactDOMRe.Style.make(
      ~display="block",
      ~fontFamily="sans-serif",
      ~marginBottom="0.25rem",
      ()
    );
  let sSelect =
    ReactDOMRe.Style.make(
      ~appearance="none",
      ~background="#eee",
      ~border="none",
      ~borderRadius="3px",
      ~color="#555",
      ~display="inline-block",
      ~fontFamily="sans-serif",
      ~fontSize="1rem",
      ~padding=".5rem 2.25rem .5rem 1rem",
      ~width="100%",
      ()
    );
  {
    ...component,
    render: (_self) =>
      <div style=sContainer>
        <label style=sLabel htmlFor=name> (str(label)) </label>
        <select id=name name style=sSelect>
          <option> (str(placeholder)) </option>
          (ReasonReact.arrayToElement(children))
        </select>
      </div>
  }
};
