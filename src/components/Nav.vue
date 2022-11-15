<template>
  <Theme :isShow="isShow" :isDark="isDark" />

  <nav class="nav pos-fix" :class="navBtm === 2 ? '' : navBtm === 1 ? 'show down' : 'show up'">
    <div class="body flex-row">
      <div class="toggle" :class="showSide ? 'close' : ''" @click="showSidebar">
        <div class="lines" aria-label="切换导航栏">
          <span class="line first"></span>
          <span class="line second"></span>
          <span class="line third" :class="showSide ? 'fade' : ''"></span>
        </div>
      </div>

      <ul class="menu">
        <li class="item" :class="item.liClass" v-for="item in nav" :key="item">
          <RouterLink :to="item.link" :class="item.aClass" :rel="item.rel" class="link pos-rel">
            <i class="ic" :class="item.iClass" v-if="item.iClass"></i>
            {{ item.name }}
          </RouterLink>
          <ul class="submenu" v-if="item.children.length > 0">
            <li class="item" v-for="child in item.children" :key="child">
              <RouterLink :to="child.link" :rel="child.rel" :class="child.iClass">
                <i class="ic" :class="child.iClass"></i>
                {{ child.name }}
              </RouterLink>
            </li>
          </ul>
        </li>
      </ul>
      <ul class="right">
        <li class="item theme">
          <i v-if="isDark" class="ic i-sun" @click="changeTheme" data-theme></i>
          <i v-if="!isDark" class="ic i-moon" @click="changeTheme" data-theme="dark"></i>
        </li>
        <li class="item search">
          <i class="ic i-search" @click="searchArticles"></i>
        </li>
      </ul>
    </div>
  </nav>

  <Brand />

  <BgImage />
  <Search :showSearch="showSearch" @close="closeSearchDialog" />
</template>
<script setup>
import { RouterLink } from "vue-router";
import Theme from "./Theme.vue";
import Search from "./Search.vue";
import config from "./../../public/config.js";
import Brand from "./Brand.vue";
import BgImage from "./BgImage.vue";
import { onMounted, ref, onUnmounted, toRefs, nextTick } from "vue";
import { store } from "@/stores/store.js";
import anime from "animejs/lib/anime.es.js";

const { nav } = config;
const state = store();

//切换黑白背景
const isDark = ref(true); // 白天黑夜 default 白天
const isShow = ref(false); // 是否显示 default 不显示
onMounted(() => {
  const isSun = localStorage.getItem("isDark");
  const HTML = document.documentElement;
  //初始化读取localStorage数据 判断主题颜色
  if (isSun) {
    isDark.value = Number(isSun) === 0 ? false : true;
    state.isDark = isDark.value ? 1 : 0;

    if (!isDark.value) {
      HTML.setAttribute("data-theme", "dark");
    } else {
      HTML.setAttribute("data-theme", "");
    }
  }
});

const changeTheme = () => {
  const HTML = document.documentElement;

  isDark.value = !isDark.value;
  isShow.value = !isShow.value;
  //background color
  localStorage.setItem("isDark", isDark.value ? 1 : 0);
  state.isDark = isDark.value ? 1 : 0;
  if (!isDark.value) {
    HTML.setAttribute("data-theme", "dark");
  } else {
    HTML.setAttribute("data-theme", "");
  }
  // switch white and dark
  setTimeout(() => {
    isDark.value = !isDark.value;
  }, 200);
  //hidden animation ,stop for 2500ms
  setTimeout(() => {
    isShow.value = !isShow.value;
    isDark.value = !isDark.value;
  }, 2500);
};
//search component
const showSearch = ref(false);
const searchArticles = () => {
  showSearch.value = true;
};
const closeSearchDialog = (value) => {
  showSearch.value = value;
};

const navBtm = ref(2);
let scroll = 0;
let offsetWave = null;

onMounted(() => {
  offsetWave = document.getElementById("brand").offsetHeight;
  window.addEventListener("scroll", scrollTop, true);
});

const scrollTop = () => {
  const newScroll =
    document.documentElement.scrollTop || document.body.scrollTop;

  if (newScroll > scroll) {
    //往下拉
    newScroll < offsetWave ? (navBtm.value = 2) : (navBtm.value = 1);
  } else {
    // 往上拉
    newScroll < offsetWave ? (navBtm.value = 2) : (navBtm.value = 0);
  }
  scroll = newScroll;
};

onUnmounted(() => {
  window.removeEventListener("scroll", scrollTop);
});
const { showSide } = toRefs(state);

const showSidebar = () => {
  showSide.value = !showSide.value;
};
</script>

<style lang="scss" scoped>
.up {
  transform: translateY(0);
}

.down {
  transform: translateY(-100%);
}

.show {
  background: var(--nav-bg);
  box-shadow: 0.1rem 0.1rem 0.2rem var(--grey-9-a1);
  text-shadow: 0 0 0.0625rem var(--grey-9-a1);
  color: var(--text-color);

  .line {
    background: var(--text-color);
    box-shadow: 0 0 0.0625rem var(--grey-9-a1);
  }

  .item.active > a,
  .item.expand > a {
    color: var(--color-aqua);
    opacity: 1;
  }
}

.nav {
  width: 100%;
  height: 3.125rem;
  transition: all 0.2s ease-in-out 0s;
  z-index: 1000;

  .body {
    width: 100%;
    height: 100%;
    margin: 0 auto;
    flex-wrap: nowrap;
    width: calc(100% - 0.625rem);

    .toggle {
      display: none;

      .lines {
        width: 1.375rem;
        padding: 1.25rem;
        box-sizing: unset;
      }
    }

    @media (max-width: 991px) {
      .toggle {
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
      }
    }
  }

  .menu {
    padding: 0.625rem 0;
    margin: 0;
    width: 100%;

    .item {
      display: inline-block;
      position: relative;
      padding: 0 0.625rem;
      letter-spacing: 0.0625rem;
      text-align: center;

      a:hover {
        color: currentColor;
      }

      .ic {
        margin-right: 0.5rem;
      }

      .submenu {
        display: none;
        position: absolute;
        margin-top: 0.5rem;
        padding: 0;
        width: -webkit-max-content;
        width: -moz-max-content;
        width: max-content;
        background-color: var(--grey-9-a5);
        box-shadow: 0 0.3125rem 1.25rem -0.25rem var(--grey-9-a1);
        border-radius: 0.625rem;

        .item {
          display: block;

          a {
            display: inline-block;
            padding: 0.3rem 0.7rem;
            width: 100%;
            text-shadow: none;
          }

          a::before {
            content: none;
          }
        }

        .item:hover a {
          transform: translateX(0.3rem);
        }

        .item.active a,
        .item:hover a {
          opacity: 1;
        }
      }

      .submenu .item:first-child:hover {
        border-radius: 0.625rem 0.625rem 0 0;
      }

      .submenu .item:last-child:hover {
        border-radius: 0 0 0.625rem 0.625rem;
      }

      .submenu .item.active,
      .submenu .item:hover {
        color: var(--grey-0);
        background-color: var(--color-morandi-blue);
        box-shadow: 0 0.125rem 0.75rem var(--color-morandi-blue);
        opacity: 0.9;
        border-radius: 0.625rem;
      }

      .submenu {
        animation: slideUpIn 0.3s;
      }

      .submenu::before {
        position: absolute;
        top: -1.25rem;
        left: 0;
        width: 100%;
        height: 2.5rem;
        content: "";
      }

      .submenu:hover {
        display: block;
      }
    }

    .item:not(.title) a {
      display: block;
      font-size: 1em;
    }

    .item:not(.title) a::before {
      content: "";
      position: absolute;
      width: 0;
      height: 0.1875rem;
      bottom: 0;
      border-radius: 0.125rem;
      left: 50%;
      transform: translateX(-50%);
      background-color: currentColor;
    }

    .item.active:not(.dropdown) a::before,
    .item:not(.dropdown):hover a::before {
      width: 80%;
    }

    .item.dropdown > a::after {
      content: "";
      display: inline-block;
      margin-left: 0.3rem;
      vertical-align: middle;
      border: 0.3rem solid transparent;
      border-top-color: currentColor;
      border-bottom: 0;
    }

    .item.dropdown:hover .submenu {
      display: block;
    }

    @media (max-width: 767px) {
      .item {
        display: none;
      }

      .item.title {
        display: block;
      }
    }
  }

  .right {
    display: inline-flex;
    align-items: center;
    justify-content: center;

    .item {
      padding: 0.625rem 0.5rem;
      cursor: pointer;
    }

    .i-sun {
      font-size: 1.125em;
    }
  }

  @media (min-width: 1200px) {
    .body {
      width: 72.5rem;
    }
  }

  @media (min-width: 1600px) {
    .body {
      width: 73%;
    }
  }
}

.toggle {
  line-height: 0;
  cursor: pointer;
}

.toggle .line {
  background: var(--header-text-color);
  display: inline-block;
  height: 0.125rem;
  left: 0;
  position: relative;
  border-radius: 0.0625rem;
  top: 0;
  transition: all 0.4s;
  vertical-align: top;
  width: 100%;
  box-shadow: 0 0 0.5rem rgba(0, 0, 0, 0.5);
}

.toggle .line:not(:first-child) {
  margin-top: 0.1875rem;
}

.close {
  .first {
    transform: translateY(0.3125rem) rotate(-45deg);
  }

  .second {
    transform: rotate(45deg);
  }

  .third {
    transform: translateY(1rem);
    transition: all 0.5s;
  }

  .fade {
    opacity: 0;
  }
}
</style>
