<template>
  <div class="theme pos-fix" :class="[isDark ? 'dark' : '', isShow ? 'show' : '']">
    <div class="planet pos-fix">
      <div class="sun pos-abs"></div>
      <div class="moon pos-abs"></div>
    </div>
    <div class="body pos-abs">
      <div class="face">
        <section class="eyes left">
          <span class="pupil"></span>
        </section>
        <section class="eyes right">
          <span class="pupil"></span>
        </section>
        <span class="nose"></span>
      </div>
    </div>
  </div>
</template>
<script setup>
import { defineProps, toRefs } from "vue";
const props = defineProps({ isDark: Boolean, isShow: Boolean });
const { isDark, isShow } = toRefs(props);
</script>
<style scoped lang="scss">
.theme.show {
  display: block !important;
}

.theme {
  left: 0;
  right: 0;
  top: 0;
  bottom: 0;
  z-index: 9999;
  display: none;
  background: linear-gradient(to top, #fddb92 0, #d1fdff 80%);
  .planet {
    left: -50%;
    top: -50%;
    width: 200%;
    height: 200%;
    animation: rotate 2s cubic-bezier(0.7, 0, 0, 1);
    transform-origin: center bottom;
    .moon,
    .sun {
      border-radius: 100%;
      left: 55%;
      top: 32%;
    }

    .sun {
      height: 40px;
      width: 40px;
      background: #ffee94;
      box-shadow: 0 0 40px #ffee94;
      opacity: 1;
    }

    .moon {
      height: 24px;
      width: 24px;
      background: #eee;
      box-shadow: 0 0 20px #fff;
      opacity: 0;
    }
  }

  .body {
    display: block;
    bottom: -20px;
    height: 140px;
    width: 135px;
    left: 50%;
    margin-left: -100px;
    background: #777;
    transition: all 0.25s ease-in-out;
    animation: slideUpBigIn 1s;

    .eyes {
      display: block;
      position: absolute;
      background: #ffee94;
      height: 40px;
      width: 40px;
      border-radius: 100%;
      bottom: 80px;
    }

    .eyes.left {
      left: 12px;
    }

    .eyes.right {
      right: 12px;
    }
    .eyes .pupil,
    .nose {
      display: block;
      position: relative;
      background: #ffb399;
      border-radius: 100%;
      margin: 0 auto;
    }

    .eyes .pupil {
      height: 100%;
      width: 5px;
      transition: width 1s 0.5s ease-in-out;
    }

    .nose {
      top: 45px;
      height: 10px;
      width: 10px;
    }
  }

  .body:after,
  .body:before {
    position: absolute;
    content: "";
    width: 0;
    height: 0;
    border-bottom: 20px solid #777;
    top: -20px;
    transition: all 0.25s ease-in-out;
  }

  .body:before {
    border-left: 0 solid transparent;
    border-right: 30px solid transparent;
    left: 0;
  }

  .body:after {
    border-right: 0 solid transparent;
    border-left: 30px solid transparent;
    right: 0;
  }
}

.theme:before {
  content: "";
  position: absolute;
  left: 0;
  right: 0;
  top: 0;
  bottom: 0;
  opacity: 0;
  background: linear-gradient(to top, #30cfd0 0, #330867 100%);
  transition: 2s ease all;
}

.theme.dark:before {
  opacity: 1;
}
.theme.dark {
  .sun {
    opacity: 0;
  }
  .moon {
    opacity: 1;
  }
  .body {
    background: #444;
    .eyes .pupil {
      height: 90%;
      width: 34px;
      margin: 5% auto;
    }
  }

  .body:before {
    border-bottom: 20px solid #444;
  }
  .body:after {
    border-bottom: 20px solid #444;
  }
}
</style>